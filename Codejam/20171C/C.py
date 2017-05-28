from decimal import *
import math
getcontext().prec = 15

t = int(input())
for _ in range(t):
    (n,k) = input().split(' ')
    n = int(n)
    k = int(k)
    u = Decimal(input())
    data = input().split(' ')
    for i in range(n):
        data[i] = Decimal(data[i])
    #curr = Decimal(0)
    res = Decimal(-1)
    l = Decimal(min(data))
    h = Decimal(1)
    for j in range(1000):
        mid = Decimal(l+h)/Decimal(2)
        uneed=Decimal(0)
        for i in range(n):
            if data[i]<mid:
                uneed += mid-data[i]
        if (uneed<=u):
            l = mid+Decimal("0.000001")
        else:
            h = mid-Decimal("0.000001")
        #curr += Decimal(0.0001)
    print("Case #%d: %.6f" % (_+1,pow(l-Decimal("0.000001"),Decimal(n))))
        
