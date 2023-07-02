import numpy as np

n = int(input())
a = []
b = []
for i in range(n):
	now = input().split()
	x = [int(now[i]) for i in range(n) ]
	a.append(x)
	b.append(int(now[n]))

# print(a)
# print(b)
try:
	ans = np.linalg.solve(a,b)
	for i in ans:
		print("%.2f" % i)
except:
	print("No Solution")