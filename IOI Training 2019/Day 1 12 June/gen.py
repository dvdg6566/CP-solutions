# from random import * 
# for i in range(10):
# 	s  =""
# 	for j in range(10):
# 		s += str(randint(0,10))
# 		s+=' '
# 	print(s)

from math import *
A = [[0 for i in range(10)] for j in range(10) ]

for i in range(len(A)):
	for j in range(len(A)):
		x = sqrt(i*i+j*j)
		A[i][j] = floor(x)

for i in A:print(i)