isPrime = [True for i in range(1024)]
isPrime[0] = isPrime[1] = False
primes = []
for i in range(33):
	if not isPrime[i]:
		continue
	j = i * i
	while j < 1024:
		isPrime[j] = False
		j += i

for i in range(1001):
	if (isPrime[i]):
		primes.append(i)

def pp (a,s):
	s += ':'
	for i in a:
		s += ' '
		s += str(i)
	s += '\n'
	print(s)

while True:
	try:
		s = input()
		x = [int(i) for i in s.split()]
		r = [i for i in primes if i <= x[0]]
		t = [1] + r + [x[0]]
		#if(isPrime[x[0]]):t.pop()
		if(len(r)%2 == 0):
			c = int(len(t)/2-1)
			l = c - x[1] +1
			u = c + x[1]
			if(l<0):
				l = 0
			if (u > len(t)-1):
				u = len(t)-1
			pp(t[l:u],s)
		else:
			c = int((len(t)-1)/2)
			l = c - x[1]
			u = c + x[1]
			if(l<0):
				l =  0
				u = len(t)-1
			pp(t[l:u],s)
	except EOFError:
		break