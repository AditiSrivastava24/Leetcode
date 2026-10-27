// Last updated: 10/27/2026, 10:04:22 AM
1#include <vector>
2#include <string>
3
4class Solution {
5public:
6    std::vector<std::string> createGrid(int m, int n) {
7        // Initialize an m x n grid filled entirely with obstacles ('#')
8        std::vector<std::string> grid(m, std::string(n, '#'));
9        
10        // 1. Fill the entire top row with free cells ('.')
11        for (int j = 0; j < n; ++j) {
12            grid[0][j] = '.';
13        }
14        
15        // 2. Fill the entire last column with free cells ('.')
16        for (int i = 0; i < m; ++i) {
17            grid[i][n - 1] = '.';
18        }
19        
20        return grid;
21    }
22};
23