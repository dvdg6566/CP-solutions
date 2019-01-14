i:bisPrime = [True for i in range(1000000)]
isPrime[0] = isPrime[1] = False
primes = []
for i in range(1000):
	if not isPrime[i]:
		continue
	j = i * i
	while j < 1000000:
		isPrime[j] = False
		j += i

while True:
    try:
        i = input()
        if(isPrime[int(i)]):
            p = i[::-1]
            if(isPrime[int(p)] and p!=i):
                print(i + " is emirp.")
            else:
                print(i + " is prime.")

        else:
            print(i + " is not prime.")
    except EOFError:
        break
    