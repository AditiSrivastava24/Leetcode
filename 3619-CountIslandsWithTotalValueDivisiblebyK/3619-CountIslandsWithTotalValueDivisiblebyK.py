# Last updated: 10/26/2026, 4:22:37 PM
1class Solution:
2    def countIslands(self, grid: list[list[int]], k: int) -> int:
3        m, n = len(grid), len(grid[0])
4        island_count = 0
5        
6        def dfs(r: int, c: int) -> int:
7            # Add the current cell's value and mark it visited by sinking it
8            total_sum = grid[r][c]
9            grid[r][c] = 0 
10            
11            # Explore 4-directional neighbors
12            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
13                nr, nc = r + dr, c + dc
14                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] > 0:
15                    total_sum += dfs(nr, nc)
16                    
17            return total_sum
18
19        # Iterate through every cell in the grid
20        for i in range(m):
21            for j in range(n):
22                if grid[i][j] > 0:  # Found an unvisited piece of land
23                    total_value = dfs(i, j)
24                    if total_value % k == 0:
25                        island_count += 1
26                        
27        return island_count
28