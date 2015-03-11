#!/usr/bin/python2
#coding:utf8

def sqrt(x):
	if x >= 0:
		ans = 0
		while ans * ans < x: 
			ans += 1
		if ans * ans != x:
			print x, 
			return None
		else:
			return ans
	else:
		print x, #is negative number
		return None

def dive_in(x):
	if x > 0:
		print x,
		m = dive_in(x-1),
		return m
	else:
		return 0

def _sqrt(x, e):
	low = 0
	high = x
	guess = (low + high)/2.0
	cnt = 1
	while abs(guess ** 2 - x) > e :
		if guess ** 2 < x:
			low = guess
		else:
			high = guess

		guess = (low + high)/2.0
		cnt += 1

	print cnt, guess,e
			

if __name__ == '__main__':
	for i in range(20):
		a = 10 ** i + 5
		e = 1.0 / (10**i)
		_sqrt(a, e)
