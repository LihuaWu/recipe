#!/usr/bin/python2

import optparse
import ConfigParser
import gevent
import gevent.queue
import logging

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
			return None
		else:
			yield line
	

if __name__ == '__main__':
	pass
