N = 1000
s = ""
import random
for i in range(N):
	s += str(random.randint(0,1))

f = open("in.txt","w")
f.write(s)