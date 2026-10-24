import sys

n, t = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))

left = 0
current_time = 0
max_books = 0

for right in range(n):
    current_time += a[right]
    
    while current_time > t:
        current_time -= a[left]
        left += 1
        
    max_books = max(max_books, right - left + 1)

print(max_books)