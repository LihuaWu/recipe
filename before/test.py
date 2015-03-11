#!/usr/bin/python2
#coding:utf8

from functools import wraps

def log(fn):
	a = "log"
	@wraps(fn)
	def wrapper(*args):
		args += (a,)
		fn(*args)
	return wrapper

@log
def hello(a, *args):
	print a

class A:
	b = "sdf"
	def test(self):
		print self.__dict__
	pass

if __name__ == '__main__':

	a = A()
	print a.__dict__
	a.b = 6
	print a.__dict__
	a.test()
	a.b = 7
	print a.__dict__
	a.test()
	if "c" not in a.__dict__:
		a.__dict__['c'] = 5
	a.test()
	print a.c
	pass
