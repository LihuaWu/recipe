#!/usr/bin/python2
#coding:utf8

import optparse
import ConfigParser
import logging
import urlparse
import urllib2
import urllib
import zlib

import gevent
import gevent.queue
import pyquery
import lxml

import rewrite

def parse_args():
	"""Read and parse options from command line
	Initialize logging
	"""

	usage = """usage: %prog [options]
To crawl pages from web in terms of special URL patterns."""

	parser = optparse.OptionParser(usage=usage, version='%prog 1.0.0.0')	
	parser.add_option('-c', dest='filename',
						help='read config file', metavar='FILE')

	parser.add_option('-l', '--log', dest='log', action = 'store_true',
						default = False, help='start logging')

	options, args = parser.parse_args()
	if options.filename is None:
		print parser.format_help()
		parser.exit()
	else:
		if options.log:
			import logging.config
			logging.config.fileConfig('logging.conf')
		return options.filename

def parse_config_file(filename): 
	"""Read configuration file and return as a dict

	Keyword arguments:
	filename -- configuration filename
	"""
	config = ConfigParser.ConfigParser()
	config.read(filename)
	confs = config.items('spider',True)
	return dict(confs)

def read_file(filename):
	"""Read content from file and return a generator
	
	Keyword arguments:
	filename -- file's name

	Return values:
	line generator
	"""
	try:
		f = open(filename)
		while True:
			line = f.readline()
			if not line:
				break
			else:
				yield line
	finally:
		f.close()	

def get_url_response(url, header_dict = {}, post_dict = {},
	timeout = 0, use_gzip = False):

	url = str(url)
	#load post data
	if len(post_dict) > 0:
		post_data = urllib.urlencode(post_dict)
		req = urllib2.Request(url, post_data)
		req.add_header('Content-Type', 'application/x-www-form-urlencoded')
	else:
		req = urllib2.Request(url)
	#load header data
	if len(header_dict) > 0:
		for k, v in header_dict.iteritems():
			req.add_header(k, v)
	default_header_dict = {
		'User-Agent' :'Mozilla/5.0',
		'Cache-Control' : 'no-cache',
		'Accept' : '*/*',
		'Connection' : 'Keep-Alive'}
	for k, v in default_header_dict.iteritems():
		req.add_header(k, v)

	#add gzip support
	if use_gzip:
		req.add_header('Accept-Encoding', 'gzip, deflate');

	if timeout > 0:
		response = urllib2.urlopen(req, timeout = timeout)
	else:
		response = urllib2.urlopen(req)

	return response


def get_html(url, header_dict = {}, post_dict = {},
			timeout = 0, use_gzip = False):

	response = get_url_response(url, header_dict, post_dict, timeout, use_gzip)

	html = response.read()

	resp_info = response.info()

	response.close()

	#gzip support
	if ("Content-Encoding" in resp_info and 
		resp_info['Content-Encoding'] == 'gzip'):
		html = zlib.decompress(html, 16 + zlib.MAX_WBITS) 

	return html


def fetch_urls(url):
	"""
	extract urls from the input url html page and return a generator
	
	Keyword arguments:
	url: URL
	
	Return values:
	url generator
	"""
	html = get_html(url)

	d = pyquery.PyQuery(html)
	for i in d.find('a'):
		m = i.values()
		url_filter = ['javascript:', '#jump']
		is_filtered = False
		for k, v in i.items():
			#filter by node key
			if k != "href":	
				continue

			#filter by node value
			for p in url_filter:
				if v.startswith(p):
					is_filtered = True
					break
			if is_filtered:
				continue

			#recognize and rewrite relative url to absolute url
			elif "http" not in v:
				v = rewrite.url_rewrite(v) 
				v = "%s/%s" %(i.base_url, v)	
			yield v

if __name__ == '__main__':
	pass
