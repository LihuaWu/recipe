#!/usr/bin/python2
#coding:utf8

import gevent.queue
import pybloomfilter

import utils
import log
import seed

def main():
	_, confs = utils.parse_args()

	#read 
	crawl_timeout = float(confs['spider']['crawl_timeout'])
	crawl_interval = float(confs['spider']['crawl_interval'])
	max_depth = int(confs['spider']['max_depth'])
	bf = pybloomfilter.BloomFilter(100000, 0.0001, confs['BloomFilter']['bf_file'])

	#initialize task queue
	tasks = gevent.queue.Queue()
	for line in utils.read_file(confs['spider']['url_list_file']):
		line = line.strip()
		#logger.info('queue in url:%s' %line)
		log.info('queue in url:%s' %line)
		tasks.put_nowait(seed.Seed(0, line))

	thread_num = int(confs['spider']['thread_count'])

	def worker(n):
		while not tasks.empty():
			depth, url = tasks.get()
			if depth > max_depth:
				log.info("worker%s url:%s exceed max depth %s." %(n, url, max_depth))
				continue
			if url in bf:
				log.info('worker%s url:%s already accessed' %(n, url))
			else:
				bf.add(url)
				log.info('worker%s fetching url:%s' %(n, url))
				url_list = utils.fetch_urls(url, crawl_timeout)
				for u in url_list:
					tasks.put_nowait(seed.Seed(depth + 1, u))
					log.info('queue in url:%s' %u)
				gevent.sleep(crawl_interval)

		log.info('worker%s quit.' %n)
	threads = [gevent.spawn(worker, i) for i in range(thread_num)]
	gevent.joinall(threads) 


if __name__ == '__main__':
	main()
	pass
