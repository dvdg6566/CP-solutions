from random import randint
N = 5000
R = 50
f = open('sample-2.in','w')
f.write("5000 50\n")
for i in range(R):
	s = ""
	s += str(randint(1,2)) + ' '
	a = randint(0,N-2)
	b = randint(a,N-1)
	c = randint(0,100000)
	s += str(a) + ' '+str(b)+ ' '+str(c) +'\n'
	f.write(s)