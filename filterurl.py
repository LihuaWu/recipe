#!/usr/bin/python2
#coding:utf8

def is_filtered(node):
	for k, v in node.items():
		if k != "href":
			continue
		
