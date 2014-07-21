#!/usr/bin/python2
#coding:utf8

import utils
import logging
import gevent.queue

def main():
	filename = utils.parse_args()

	confs = utils.parse_config_file(filename)

	logger = logging.getLogger('mini_spider')

	#initialize task queue
	tasks = gevent.queue.Queue()
	for line in utils.read_file(confs['url_list_file']):
		line = line.strip()
		logger.info('queue in url:%s' %line)
		tasks.put_nowait(line)

	while not tasks.empty():
		url = tasks.get()
		logger.info('fetching url:%s' %url)
		url_list = utils.fetch_urls(url)

if __name__ == '__main__':
	main()
	pass
