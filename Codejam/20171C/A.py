import math
from decimal import *

getcontext().prec = 15

t = int(input())

for _ in range(t):
    (n,k) = input().split(' ')
    n = int(n)
    k = int(k)
    data = []
    rhdata = []
    for i in range(n):
        subdata = input().split(' ')
        data.append((Decimal(subdata[1])*Decimal(subdata[0]),Decimal(subdata[1]),Decimal(subdata[0])))
    data.sort();
    rhdata.sort();
    #print(data)

    res = Decimal(0)

    for i in range(n):
        hsum = data[i][0];
        selected = 1
        for j in range(n):
            if selected>=k:
                break
            if (i!=n-j-1 and data[n-j-1][2]<=data[i][2] ):
                hsum += data[n-j-1][0]
                selected+=1
        if (selected!=k):
            continue
        r = Decimal(data[i][2])
        #print(hsum)
        subres = Decimal(math.pi)*r*r+2*Decimal(math.pi)*hsum
        res = max(res,subres)

    print("Case #%d: %.9f" % (_+1,res))
    

