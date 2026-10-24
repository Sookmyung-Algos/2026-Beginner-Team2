import sys

input = sys.stdin.readline

n = int(input())
elements = list(map(int, input().split()))

max_val = max(elements)
count = [0] * (max_val + 1)

for num in elements:
    count[num] += 1

dp = [0] * (max_val + 1)
dp[1] = count[1]

for i in range(2, max_val + 1):
    dp[i] = max(dp[i - 1], dp[i - 2] + i * count[i])

print(dp[max_val])