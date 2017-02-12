from decimal import *
from collections import defaultdict
import re
import pprint
import sys

pp = pprint.PrettyPrinter(indent=4)
getcontext().prec = 50

yset = [4, 6, 8, 10, 12, 20]

t = 1#int(input())

#dp[level][branch] = (finallevel,choosedai)
#data[..] = 1d10+100 -> (1,10,100)

def del0(arr):
    needdel = []
    for i in arr:
        if (arr[i]==0):
            needdel.append(i)
    
    for i in needdel:
        del arr[i]

def sub(level):
    if level<0:
        return
    for i in range(1,branchn+1): #i = choosing branch
        final = defaultdict(int)
        count = 0
        for j in range(1,branchn+1): #j = next lv branch
            finalref = dp[level+1][j][0]
            count = count + dp[level+1][j][1]
            for k in finalref: #final key
                kinrange = True if k<=branchn else False
                knew = k-i
                if (knew<=1):
                    knew=1
                #print(str(knew)+' '+str(final[knew]))
                final[knew] = final[knew]+finalref[k]
                if (kinrange):
                    count = count + ((k-knew) * finalref[k])
                else:
                    if (branchn+1-knew > 0):
                        count = count + ((branchn+1-knew) * finalref[k])
        del0(final)
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
        dp = [[None for _ in range(branchn+1)] for __ in range(0,leveln)]
        #make base case
        for j in range(1,branchn+1):
            dp[leveln-1][j] = (defaultdict(int),(1) if j>=need else (0))
        #print(dp)
        
        if (leveln>1):
            for j in range(1,branchn+1):
                count = 0
                start = need-j
                for k in range(1,branchn+1):
                    if (k+j>=need):
                        count+=1
                final = defaultdict(int)
                if start<=1:
                    start=1
                final[start] = 1
                dp[leveln-2][j] = (final,(count))
        #pp.pprint(dp)
        
        if (leveln>2):
            sub(leveln-3)

        for j in range(1,branchn+1):
            res[i] = res[i]+Decimal(dp[0][j][1])

        res[i] = res[i]/samplespace
        res[i] = res[i].quantize(Decimal('0.000001'))
        #pp.pprint(dp)

    
    return max(res)

for y in yset:
	for x in range(1,21):
		#need,n = input().split(' ');
		for need in range(1,x*y+1):
			n = 1#int(n)
			#data_raw = [_ for _ in input().split(' ')]
			data_raw = [(str(x)+"d"+str(y))]
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
			printstr = str(x)+","+str(y)+","+str(need)+","+str(process())
			print(printstr)
			print(printstr, file=sys.stderr)

wait = input("Pausing")
