def gcd(a,b): # a smaller
    if(a==0):
        return b
    return gcd(b%a,a)

def lcmh(a,b):
    return a*b/gcd(a,b)    

def lcm(a,b,c,d):
    c = lcmh(d,c)
    b = lcmh(min(b,c),max(b,c))
    a = lcmh(min(a,b),max(a,b))
    return a

from math import floor,inf

def run(A,V,i):
    bestlow = 0
    besthigh = inf
    for a in range(3,A[0]):
        for b in range(2,a):
            for c in range(1,b):
                for d in range(c):
                    l = lcm(V[a],V[b],V[c],V[d])
                    if(i%l == 0):
                        print(str(int(i)) + ' ' + str(int(i)))
                        return
                    else:
                        x = floor(i/l)
                        y = x+1
                    bestlow = max(bestlow,x*l)
                    besthigh = min(besthigh,y*l)
    print(str(int(bestlow)) + ' ' + str(int(besthigh)))

while(True):
    A = [int(i) for i in input().split(' ')]
    if (A == [0,0]):
        break
    V = []
    for i in range(A[0]):V.append(int(input()))
    V.sort()
    H = []
    for i in range(A[1]):H.append(int(input()))
    for x in H:
        run(A,V,x)