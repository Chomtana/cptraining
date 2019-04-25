t = int(input().strip())
for _ in range(t):
  n = int(input().strip())
  #n = _+1
  nstr = str(n)
  a = "1"+("0"*(len(nstr)-1))
  b = n - int(a)
  bstr = ("0"*(len(a)-len(str(b)))) + str(b)
  bstr = list(bstr)
  a = list(a)
  for i in range(len(bstr)):
    x = bstr[i]
    if (x=='4'):
      a[i] = str(int(a[i])+1)
      bstr[i] = str(int(bstr[i])-1)
  print("Case #"+str(_+1)+": "+str(int("".join(a)))+" "+str(int("".join(bstr))))
  #if (int("".join(a)) + int("".join(bstr)) != n): print("WA "+str(n))
  
  