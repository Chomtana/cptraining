import ast

t = int(input())
for _ in range(1,t+1):
  expr = input()
  print(expr)
  tree = ast.parse(expr)
  for node in ast.walk(tree):
    print(node)
  print("Case #{}: ".format(_))