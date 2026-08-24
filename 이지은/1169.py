import sys

N, M = map(int, sys.stdin.readline().split())
arr = []
visited = [False] * 7

def dfs(depth, start_idx):
    if depth == N:
        print(*arr)
        return

    for i in range(1, 7):
        if M == 1:
            arr.append(i)
            dfs(depth + 1, i)
            arr.pop()
        elif M == 2:
            if i >= start_idx:
                arr.append(i)
                dfs(depth + 1, i)
                arr.pop()
        elif M == 3:
            if not visited[i]:
                visited[i] = True
                arr.append(i)
                dfs(depth + 1, i)
                visited[i] = False
                arr.pop()

dfs(0, 1)