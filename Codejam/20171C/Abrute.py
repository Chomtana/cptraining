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
        data.append((Decimal(subdata[1]),Decimal(subdata[0])))
        rhdata.append(Decimal(data[i][0]*data[i][1]))
    data.sort();
    rhdata.sort();
    #print(data)

    res = Decimal(0)

    permu = itertools.permutations(data)

    for i in range(permu):
        hsum = rhdata[i];
        selected = 1
        for j in range(n):
            if selected>=k:
                break
            if (i!=n-j-1 and data[n-j-1][1]<=data[i][1] ):
                hsum += rhdata[n-j-1]
                selected+=1
        if (selected!=k):
            continue
        r = Decimal(data[i][1])
        #print(hsum)
        subres = Decimal(math.pi)*r*r+2*Decimal(math.pi)*hsum
        res = max(res,subres)

    print("Case #%d: %.9f" % (_+1,res))
    

