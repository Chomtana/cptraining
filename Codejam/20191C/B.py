import sys

t,f = map(int,input().strip().split())

def calrowcol(row,col):
  return row*5+col+1

def chari(c):
  return ord(c)-ord('A')

def ichar(i):
  return chr(i+ord('A'))

data = [[-1 for i in range(5)] for i in range(119)]
f= open("Bmove.txt","w+")

for _ in range(1,t+1):
  totalmove = 0

  for i in range(119): 
    for j in range(5): 
      data[i][j] = -1

  coltarget = [-1,-1,-1,-1,-1]
  for col in range(5):
    #do col 0
    count = [0,0,0,0,0]
    for i in range(119):
      isdo = True
      for j in range(col):
        if data[i][j] != coltarget[j]:
          isdo = False
          break
      if isdo:
        print(calrowcol(i,col))
        totalmove+=1
        sys.stdout.flush()
        res = chari(input().strip())
        data[i][col] = res
        count[res]+=1

    mini = -1
    minval = 999999
    for i in range(5):
      if i in coltarget: continue
      if (count[i]<minval):
        minval = count[i]
        mini = i
    coltarget[col] = mini
      
    
  
  
  f.write(str(totalmove)+"\n")
  print("".join(map(ichar,coltarget)))
  sys.stdout.flush()

  verdict = input().strip()

