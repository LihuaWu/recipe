#!/usr/bin/python2 
#coding:gbk

import locale

from encodings.aliases import aliases

def guess_encoding(data):
	"""
	Given a byte string , attempt to decode it.
	read encoings from encodings module

	"""
	#encodings = aliases.keys()
	encodings = [
		'gb2312', 'gbk', 'gb18030','hz', #cn
		'big5', #tw
		'big5hkscs', #hk
		'latin-1'  #west euro
		
	]

	for enc in encodings:
		try:
			decoded = unicode(data, enc)
		except (UnicodeError, LookupError):
			pass
		else:
			return  True, enc, decoded
	return False, None,data
	
	

if __name__ == '__main__':
	pass
