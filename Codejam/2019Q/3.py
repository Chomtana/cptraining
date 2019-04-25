def gcd(a,b):
  #if (a<b): return gcd(b,a)
  if (b==0):
    return a
  else:
    return gcd(b,a%b)
    
#print(gcd(217,1891))

def isqrt(n):
  x = n
  y = (x + 1) // 2
  while y < x:
    x = y
    y = (x + n // x) // 2
  return x

t = int(input().strip())
for _ in range(t):
  data = []
  resolve = [(0,0)]*1000
  n,l = map(int,input().strip().split())    
  data = list(map(int,input().strip().split()))
  
  hasnoteq = False
  for i in range(l-1):
    if (data[i]!=data[i+1]):
      g = gcd(data[i],data[i+1])
      resolve[i] = (data[i]//g,g)
      resolve[i+1] = (g,data[i+1]//g)
      #print(resolve[i],resolve[i+1])
      hasnoteq = True
      def performleft(j):
        if (j<0): return
        g = resolve[j+1][0]
        resolve[j] = (data[j]//g,g)
        performleft(j-1)
        
      def performright(j):
        if (j>=l): return
        #print("j",j)
        g = resolve[j-1][1]
        resolve[j] = (g,data[j]//g)
        performright(j+1)
        
      performleft(i-1)
      performright(i+2)
        
      break
      
  #print(resolve[0:l])
      
  if (not hasnoteq):
    print("Case #"+str(_+1)+": ",end="",sep="")
    print("A"*(l+1))
    continue
    
  #print(resolve)
  
  removedup = set()
  
  for i in range(l):
    x = resolve[i]
    removedup.add(x[0])
    removedup.add(x[1])
  
  removedup = sorted(list(removedup))
  
  charmap = dict()
  
  currchar = ord('A')
  
  for x in removedup:
    charmap[x] = chr(currchar)
    currchar += 1
  
  res = ""
    
  for i in range(l):
    res += charmap[resolve[i][0]]
    
  res += charmap[resolve[l-1][1]]
  #res += charmap[resolve[l-1][0]]
  
  print("Case #"+str(_+1)+": ",end="",sep="")
  print(res)