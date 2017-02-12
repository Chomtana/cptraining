from collections import defaultdict
from decimal import *
import re

cache = dict()

getcontext().prec = 50

f = open("3generator.txt");
for line in f:
	line = line.split(',');
	cache[(Decimal(line[0]),Decimal(line[1]),Decimal(line[2]))] = Decimal(line[3])
	
t = int(input())

def process():
	global need
	needold = need
	currmax = Decimal('0.000000')
	for i in range(0,n):
		need = needold
		need = need - data[i][2]
		if need<1:
			return Decimal('1.000000').quantize(Decimal('0.000001'))
		elif need>data[i][0]*data[i][1]:
			currmax = max(currmax,Decimal('0.000000').quantize(Decimal('0.000001')))
			continue
		#print((data[i][0],data[i][1],need));
		currmax = max(currmax,cache[(data[i][0],data[i][1],need)].quantize(Decimal('0.000001')))
	return currmax

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
