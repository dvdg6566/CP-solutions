isPrime = [True for i in range(10000)]
isPrime[0] = isPrime[1] = False
primes = []
for i in range(100):
	if not isPrime[i]:
		continue
	j = i * i
	while j < 10000:
		isPrime[j] = False
		j += i

for i in range(5000):
    if(isPrime[i]):
        primes.append(i)
primes.append(1234567890)

while(True):
    x = input()
    if (x == "0"):
        break
    x = int(x)
    res = 0
    for i in range(len(primes)):
        s = primes[i]
        index = i
        while(s<x):
            index += 1
            s += primes[index]
        if(s == x):
            res += 1
    print(res)
