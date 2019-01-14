o = 2147483647
while True:
    try:
        i = input()
        r = i.split(' ')
        assert(len(r) == 3)
        r[0] = int(r[0])
        r[2] = int(r[2])
        print(i)
        if(r[0] > o):
            print("first number too big")
        if(r[2] > o):
            print("second number too big")
        if(r[1] == '+'):
            if(r[0]+r[2] > o):
                print("result too big")
        if(r[1] == '*'):
            if(r[0]*r[2] > o):
                print("result too big")
    except EOFError:
        break