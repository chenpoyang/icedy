#!/usr/bin/env python
# -*- encoding: utf-8 -*-

# 是這样的吧
def fib(n):
	a, b = 0, 1
	while a < n:
		print b
		a, b = b, a + b

def fib2(n):
	res = []
	a, b = 0, 1
	while a < n:
		res.append(b)
		a, b = b, a + b
	return res

fib(100215)
