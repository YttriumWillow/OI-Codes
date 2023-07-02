import numpy as np

n = int(input())
mtx = []
for i in range(n):
	now = [int(i) for i in input().split()]
	mtx.append(now)

# ans = np.linalg.solve(a,b)
# print(mtx)

ans = np.linalg.inv(mtx)

print(ans)
