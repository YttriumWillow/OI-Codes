n, k = [int(i) for i in input().split()]
pos = 0

for i in range(2, n + 1):
    pos = (pos + k) % i
    print(i, ":", pos + 1)
print