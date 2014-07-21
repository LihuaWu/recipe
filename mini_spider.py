#!/usr/bin/python2
import utils
import logging

def main():
	filename = utils.parse_args()
	confs = utils.parse_config_file(filename)
	logger = logging.getLogger('mini_spider')
	logger.info('hi')
	pass

if __name__ == '__main__':
	pass
