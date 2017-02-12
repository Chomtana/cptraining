from decimal import *
import re
import pprint

pp = pprint.PrettyPrinter(indent=4)
getcontext().prec = 50

t = int(input())

#dp[level][branch] = (finallevel,choosedai)
#data[..] = 1d10+100 -> (1,10,100)

def sub(level):
    if level<0:
        return
    for i in range(1,branchn+1): #i = choosing branch
        final = [0 for _ in range(len(dp[level+1][1][0]))]
        count = Decimal(0)
        for j in range(1,branchn+1): #j = next lv branch
            finalref = dp[level+1][j][0]
            count = count + dp[level+1][j][1]
            for k in range(1,len(finalref)): #final key
                kinrange = True if k<=branchn else False
                knew = k-i
                if (knew<=1):
                    knew=1
                final[knew] = final[knew]+finalref[k]
                if (kinrange):
                    count = count + (Decimal(k-knew) * finalref[k])
                else:
                    if (branchn+1-knew > 0):
                        count = count + (Decimal(branchn+1-knew) * finalref[k])
        dp[level][i] = (final,count)
    #pp.pprint(dp)
    sub(level-1)

def process():
    global branchn
    global dp
    global need
    global leveln
    global res
    needold = need
    res = [Decimal(0) for _ in range(n)]
    for i in range(0,n):
        samplespace = Decimal(data[i][1])**Decimal(data[i][0])
        need = needold
        need = need - data[i][2]
        leveln = data[i][0]
        branchn = data[i][1]
        dp = [dict() for __ in range(0,leveln)]
        #make base case
        for j in range(1,branchn+1):
            dp[leveln-1][j] = ([],Decimal(1) if j>=need else Decimal(0))
        #print(dp)
        
        if (leveln>1):
            for j in range(1,branchn+1):
                count = 0
                start = need-j
                for k in range(1,branchn+1):
                    if (k+j>=need):
                        count+=1
                final = [0 for _ in range (0,branchn+1)]
                if start<=1:
                    start=1
                if (start<=branchn):
                    if (start!=-1):
                        final[start] = 1
                else:
                    finallen = len(final)-1
                    while (finallen<start):
                        if finallen+1==start:
                            final.append(1)
                        else:
                            final.append(0)
                        finallen = len(final)-1
                dp[leveln-2][j] = (final,Decimal(count))
        #pp.pprint(dp)
        
        if (leveln>2):
            sub(leveln-3)

        for j in range(1,branchn+1):
            res[i] = res[i]+dp[0][j][1]

        res[i] = res[i]/samplespace
        res[i] = res[i].quantize(Decimal('0.000001'))
    
    return max(res)

for _t in range(1,t+1):
    need,n = input().split(' ');
    need = int(need)
    n = int(n)
    data_raw = [_ for _ in input().split(' ')]
    data = []
    for i in data_raw:
        data_p1 = re.split(r"(\d+)",i)
        #print(data_p1)
        data_1 = int(data_p1[1])
        data_2 = int(data_p1[3])
        if (data_p1[4]!=''):
            if (data_p1[4]=='-'):
                data_3 = -int(data_p1[5])
            else:
                data_3 = int(data_p1[5])
        else:
            data_3 = 0
        data.append([data_1,data_2,data_3])
        #print(data)
    print("Case #"+str(_t)+": "+str(process()))

wait = input("Pausing")
