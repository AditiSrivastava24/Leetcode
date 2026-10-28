// Last updated: 10/28/2026, 8:47:54 PM
1#include <vector>
2#include <algorithm>
3
4class Solution {
5public:
6    int minCost(std::vector<std::vector<int>>& grid) {
7        int m = grid.size();
8        int n = grid[0].size();
9        const int MAX_XOR = 1024; // Since values are <= 1023
10
11        // dp[j][k] stores whether an XOR sum 'k' is achievable at column 'j'
12        std::vector<std::vector<bool>> dp(n, std::vector<bool>(MAX_XOR, false));
13
14        // Base case: initialization for the top-left cell
15        dp[0][grid[0][0]] = true;
16
17        // Populate the first row (can only move right)
18        for (int j = 1; j < n; ++j) {
19            int val = grid[0][j];
20            for (int k = 0; k < MAX_XOR; ++k) {
21                if (dp[j - 1][k]) {
22                    dp[j][k ^ val] = true;
23                }
24            }
25        }
26
27        // Process the remaining rows
28        for (int i = 1; i < m; ++i) {
29            std::vector<std::vector<bool>> next_dp(n, std::vector<bool>(MAX_XOR, false));
30            
31            for (int j = 0; j < n; ++j) {
32                int val = grid[i][j];
33
34                for (int k = 0; k < MAX_XOR; ++k) {
35                    // Come from the top cell (same column, previous row)
36                    if (dp[j][k]) {
37                        next_dp[j][k ^ val] = true;
38                    }
39                    // Come from the left cell (previous column, same row)
40                    if (j > 0 && next_dp[j - 1][k]) {
41                        next_dp[j][k ^ val] = true;
42                    }
43                }
44            }
45            dp = std::move(next_dp);
46        }
47
48        // Find the minimum achievable XOR value at the bottom-right cell
49        for (int k = 0; k < MAX_XOR; ++k) {
50            if (dp[n - 1][k]) {
51                return k;
52            }
53        }
54
55        return -1;
56    }
57};
58