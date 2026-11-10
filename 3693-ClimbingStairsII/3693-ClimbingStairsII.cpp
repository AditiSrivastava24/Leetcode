// Last updated: 11/10/2026, 8:06:37 PM
1#include <vector>
2#include <algorithm>
3#include <climits>
4
5class Solution {
6public:
7    int climbStairs(int n, std::vector<int>& costs) {
8        // dp[i] will store the minimum cost to reach step i
9        std::vector<long long> dp(n + 1, LLONG_MAX);
10        
11        // Base case: starting at step 0 has 0 cost
12        dp[0] = 0;
13        
14        for (int i = 1; i <= n; ++i) {
15            // Check previous steps you could have jumped from (i-1, i-2, i-3)
16            for (int step = 1; step <= 3; ++step) {
17                int j = i - step;
18                if (j >= 0 && dp[j] != LLONG_MAX) {
19                    // Cost formula: dp[j] + costs[i-1] + (i - j)^2
20                    long long jumpCost = dp[j] + costs[i - 1] + (long long)step * step;
21                    dp[i] = std::min(dp[i], jumpCost);
22                }
23            }
24        }
25        
26        return dp[n];
27    }
28};
29