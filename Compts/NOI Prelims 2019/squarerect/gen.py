f = open("sample.1.in","w")
from random import randint as r
for i in range(5000100):
	a = r(1,100)
	b = r(1, 100)
	c = r(a,100)
	d = r(b,100)
	f.write(str(a))
	f.write(' ')
	f.write(str(b))
	f.write(' ')
	f.write(str(c))
	f.write(' ')
	f.write(str(d))
	f.write('\n')