# Problem:      P3904 三只小猪
# Contest:      Luogu
# URL:          https://www.luogu.com.cn/problem/P3904
# Memory Limit: 125 MB
# Time Limit:   1000 ms
# Created Time: 2023-07-06 13:45:46 

n, m = [int(i) for i in input().split()]

f = [ [0] * 51 for i in range(51)]

for i in range(1, 51):
    f[i][i] = f[i][1] = 1
    for j in range(2, i):
        f[i][j] = f[i - 1][j - 1] + j * f[i - 1][j]

print( f[n][m] )