// Last updated: 10/31/2026, 4:06:14 PM
1class Solution {
2    static constexpr int MOD = 1e9 + 7;
3public:
4    int uniquePaths(vector<vector<int>>& grid) {
5        int m = grid.size();
6        int n = grid[0].size();
7        
8        vector<vector<long long>> dpRight(m, vector<long long>(n, 0));
9        vector<vector<long long>> dpDown(m, vector<long long>(n, 0));
10        
11        if (n > 1) dpRight[0][1] = 1;
12        if (m > 1) dpDown[1][0] = 1;
13        
14        for (int i = 0; i < m; ++i) {
15            for (int j = 0; j < n; ++j) {
16                long long rWays = dpRight[i][j];
17                if (rWays > 0) {
18                    if (grid[i][j] == 1) {
19                        if (i + 1 < m) {
20                            dpDown[i + 1][j] = (dpDown[i + 1][j] + rWays) % MOD;
21                        }
22                    } else {
23                        if (j + 1 < n) {
24                            dpRight[i][j + 1] = (dpRight[i][j + 1] + rWays) % MOD;
25                        }
26                        if (i + 1 < m) {
27                            dpDown[i + 1][j] = (dpDown[i + 1][j] + rWays) % MOD;
28                        }
29                    }
30                }
31                long long dWays = dpDown[i][j];
32                if (dWays > 0) {
33                    if (grid[i][j] == 1) {
34                        if (j + 1 < n) {
35                            dpRight[i][j + 1] = (dpRight[i][j + 1] + dWays) % MOD;
36                        }
37                    } else {
38                        if (i + 1 < m) {
39                            dpDown[i + 1][j] = (dpDown[i + 1][j] + dWays) % MOD;
40                        }
41                        if (j + 1 < n) {
42                            dpRight[i][j + 1] = (dpRight[i][j + 1] + dWays) % MOD;
43                        }
44                    }
45                }
46            }
47        }
48        
49        return (dpRight[m - 1][n - 1] + dpDown[m - 1][n - 1]) % MOD;
50    }
51};
52