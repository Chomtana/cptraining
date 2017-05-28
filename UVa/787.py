import sys

for line in sys.stdin:
    data = line.split(' ')[:-1]
    res = -99999999
    for s in range(len(data)):
        mul = int(data[s])
        res = max(res,mul)
        for i in range(s+1,len(data)):
            mul *= int(data[i])
            res = max(res,mul)
    print(res)
