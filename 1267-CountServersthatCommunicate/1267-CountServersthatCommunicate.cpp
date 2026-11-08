// Last updated: 11/8/2026, 2:47:29 PM
1#include <vector>
2
3class Solution {
4public:
5    int countServers(std::vector<std::vector<int>>& grid) {
6        int m = grid.size();
7        int n = grid[0].size();
8        
9        // Trackers for total servers in each row and column
10        std::vector<int> rowCount(m, 0);
11        std::vector<int> colCount(n, 0);
12        
13        // First Pass: Count servers in each row and column
14        for (int i = 0; i < m; ++i) {
15            for (int j = 0; j < n; ++j) {
16                if (grid[i][j] == 1) {
17                    rowCount[i]++;
18                    colCount[j]++;
19                }
20            }
21        }
22        
23        int connectedServers = 0;
24        
25        // Second Pass: Check if a server can communicate
26        for (int i = 0; i < m; ++i) {
27            for (int j = 0; j < n; ++j) {
28                if (grid[i][j] == 1) {
29                    // Communicates if its row or column has more than 1 server
30                    if (rowCount[i] > 1 || colCount[j] > 1) {
31                        connectedServers++;
32                    }
33                }
34            }
35        }
36        
37        return connectedServers;
38    }
39};
40