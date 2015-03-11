#!/usr/bin/python2
#coding:utf8

import threading
from functool import wraps

lock = threading.Lock()

def _sync(func):
	@wraps(func)


