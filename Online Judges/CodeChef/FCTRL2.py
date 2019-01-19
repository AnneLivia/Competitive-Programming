a = int(input())
cont = 0
while cont < a:
    n = int(input())
    res = 1
    for i in range(1,n+1):
        res*=i
    cont+=1
    print(res)
