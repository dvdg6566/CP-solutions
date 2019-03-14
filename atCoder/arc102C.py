import sys,math

A = [int(i) for i in input().split(' ')]
N,K = A[0], A[1]

ans = math.floor(N/K) ** 3

if (K%2 == 1):
  print(ans)
  sys.exit()

res = 0
half = math.floor(K/2)
cnt = (math.floor((N - half)/K)+1)** 3
print(cnt+ans)
