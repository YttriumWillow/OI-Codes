# Problem:      P2455 [SDOI2006] 线性方程组
# Contest:      Luogu
# URL:          https://www.luogu.com.cn/problem/P2455
# Memory Limit: 128 MB
# Time Limit:   1000 ms
# Created Time: 2023-07-04 07:15:06 

import numpy as np
import sys

n = int(input())
a = []
b = []
for i in range(n):
	now = input().split()
	x = [int(now[i]) for i in range(n) ]
	a.append(x)
	b.append(int(now[n]))

ra  = np.linalg.matrix_rank(a)
rab = np.linalg.matrix_rank(a, b)

print(ra, rab)

if ra == rab[0]:
	if ra < n:
		print(-1)
		sys.exit(0)

try:
	ans = np.linalg.solve(a,b)
	t = 1
	for i in ans:
		print("x%d=%.2f" % (t, i + 0.0000001))
		t += 1
except:
	print("-1")