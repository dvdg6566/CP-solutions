while(True):
	try:
		i = [int(x) for x in input().split(' ')]
		res = 0
		for j in range(1,i[0]+1):
			res += j * (i[1] ** j)
		print(int(res))
	except EOFError:
		break