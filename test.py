#!/usr/bin/python2
#coding:gbk

import sys

if '.' not in sys.path:
	sys.path.append('.')

import unittest

class UtilTest(unittest.TestCase):
	def test_guess_encoding(self):
		import util
		s = '���������й�'
		f, enc, _ = util.guess_encoding(s)
		self.assertTrue(f, 'True')
		self.assertTrue(enc, 'gb2312')
		pass

if __name__ == '__main__':
	unittest.main()
