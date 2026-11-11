// Last updated: 11/11/2026, 7:36:48 PM
1#include <algorithm>
2
3class Solution {
4public:
5    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
6        // Strategy 1: Buy entirely individual items
7        long long strategyA = 1LL * need1 * cost1 + 1LL * need2 * cost2;
8        
9        // Strategy 2: Buy entirely combo items to cover the maximum need
10        long long strategyB = 1LL * costBoth * std::max(need1, need2);
11        
12        // Strategy 3: Buy combo items up to the overlap, then singles for the rest
13        int common_need = std::min(need1, need2);
14        long long strategyC = 1LL * costBoth * common_need 
15                            + 1LL * (need1 - common_need) * cost1 
16                            + 1LL * (need2 - common_need) * cost2;
17        
18        // Return the cheapest strategy
19        return std::min({strategyA, strategyB, strategyC});
20    }
21};
22