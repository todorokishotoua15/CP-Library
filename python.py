import sys

sys.setrecursionlimit(10000000)

MOD = 10**9 + 7

def dfs(grid, row, col, n):
    if row == n - 1 and col == n - 1:
        return 1
        
    if grid[row][col] == '*' or (row == n - 1 and col == n - 1):
        return 0
        
    count = 0
    if row + 1 < n:
        count += dfs(grid, row + 1, col, n)
    if col + 1 < n:
        count += dfs(grid, row, col + 1, n)
        
    return count % MOD

n = int(input())
grid = [input() for _ in range(n)]

print(dfs(tuple(grid), 0, 0, n))