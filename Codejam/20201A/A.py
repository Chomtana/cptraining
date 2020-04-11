t = int(input())
for _ in range(1,t+1):
  n = int(input())
  data = []
  startdata = []
  enddata = []
  firstasdata = []
  lastasdata = []
  for i in range(n):
    data.append(input())
    firstas = data[i].find('*')
    if firstas != -1:
      firstasdata.append(firstas)
      startdata.append( data[i][:firstas] )
      lastas = len(data[i]) - 1
      for j in range(len(data[i]) - 1, -1, -1):
        lastas = j
        if data[i][j] == '*': break
      enddata.append( data[i][lastas+1:] )
      lastasdata.append(lastasdata)
    else:
      startdata.append(data[i])
      enddata.append(data[i])
      firstasdata.append(-1)
      lastasdata.append(-1)
    

  global_possible = False
  
  # Choose start
  for starti in range(n):
    #print("starti", starti)
    curr = data[starti]
    possible = True
    for i in range(n):
      if i == starti: continue

      #print(data[i], startdata[i], enddata[i])

      firstas = curr.find('*')
      lastas = len(curr) - 1
      for j in range(len(curr) - 1, -1, -1):
        lastas = j
        if curr[j] == '*': break

      lastcheckstr = curr[lastas+1:]
      if len(lastcheckstr) < len(enddata[i]):
        lastcheck = enddata[i].endswith(lastcheckstr)
        if lastcheck:
          curr = curr[:lastas+1] + enddata[i]
      else:
        lastcheck = lastcheckstr.endswith(enddata[i])

      firstcheckstr = curr[:firstas]
      if len(firstcheckstr) < len(startdata[i]):
        fistcheck = startdata[i].startswith(firstcheckstr)
        if fistcheck:
          curr = startdata[i] + curr[firstas:]
      else:
        fistcheck = firstcheckstr.startswith(startdata[i])

      #print(curr, firstas, firstcheckstr, startdata[i], lastcheckstr, enddata[i])

      if not fistcheck or not lastcheck:
        possible = False
        break

      firstas = curr.find('*')
      lastas = len(curr) - 1
      for j in range(len(curr) - 1, -1, -1):
        lastas = j
        if curr[j] == '*': break

      firstas_data = data[i].find('*')
      lastas_data = len(data[i]) - 1
      for j in range(len(data[i]) - 1, -1, -1):
        lastas_data = j
        if data[i][j] == '*': break

      putback = False
      putfront = False

      if data[i][0] == '*': # can put at back
        putback = True
      if data[i][-1] == '*': # can put at front
        putfront = True

      #print(curr, 'plushere')

      if putback:
        if curr[-1] == '*':
          curr = curr[:-1] + data[i]
          continue

      if putfront:
        if curr[0] == '*':
          curr = data[i] + curr[1:]
          continue

      
      curr = curr[:firstas] + data[i] + curr[firstas:]
      

    if possible:
      curr = curr.replace('*', '')
      print("Case #%d: %s" % (_, curr))
      global_possible = True
      break

  if not global_possible:
    print("Case #%d: *" % (_))


'''
11
5
*CONUTS
*COCONUTS
*OCONUTS
*CONUTS
*S
2
*XZ
*XYZ
4
H*O
HELLO*
*HELLO
HE*
2
CO*DE
J*AM
2
CODE*
*JAM
2
A*C*E
*B*D*
2
A*C*E
*B*D
2
**Q**
*A*
10
HEL*OWORLD
HELLO*ORLD
HEL*LD
HELL*
*D
HELLOWOR*D
H*D
HEL*ORLD
HELL*LD
H*LLOWORLD
10
HEL*OWORLD
HELLO*ORLD
HEL*LD
HELL*
*D
HELLOWOR*D
H*D
HEL*ORLD
HELL*LD
H*LLOWORLD
5
HEL*
HELLOW*
HELLOWO*
HE*
HELL*
2
HEL*WO*D
*LO*RLD
'''