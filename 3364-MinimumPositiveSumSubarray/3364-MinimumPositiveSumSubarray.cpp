// Last updated: 11/14/2026, 10:46:35 PM
1#include <vector>
2#include <algorithm>
3#include <climits>
4
5using namespace std;
6
7class Solution {
8public:
9    int minimumSumSubarray(vector<int>& nums, int l, int r) {
10        int n = nums.size();
11        int minSum = INT_MAX;
12
13        // Iterate over every possible starting index
14        for (int i = 0; i < n; ++i) {
15            int currentSum = 0;
16            
17            // Extend the subarray to every valid ending index
18            for (int j = i; j < n; ++j) {
19                currentSum += nums[j];
20                int len = j - i + 1;
21                
22                // Stop early if the subarray exceeds the maximum allowed length
23                if (len > r) {
24                    break;
25                }
26                
27                // Update minimum sum if length is within [l, r] and sum is positive
28                if (len >= l && currentSum > 0) {
29                    minSum = min(minSum, currentSum);
30                }
31            }
32        }
33
34        return minSum == INT_MAX ? -1 : minSum;
35    }
36};
37