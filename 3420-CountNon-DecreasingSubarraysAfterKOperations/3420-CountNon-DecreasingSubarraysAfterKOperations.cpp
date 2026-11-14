// Last updated: 11/15/2026, 12:03:53 AM
1#include <vector>
2#include <deque>
3
4using namespace std;
5
6class Solution {
7public:
8    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
9        long long ans = 0;
10        long long cost = 0;
11        // Stores indices of elements in non-increasing order of their values
12        deque<int> dq; 
13        
14        int n = nums.size();
15        for (int i = n - 1, j = n - 1; i >= 0; --i) {
16            int num = nums[i];
17            
18            // Merge smaller elements on the right up to the current element's value
19            while (!dq.empty() && nums[dq.back()] < num) {
20                int l = dq.back();
21                dq.pop_back();
22                int r = dq.empty() ? j + 1 : dq.back();
23                cost += static_cast<long long>(r - l) * (num - nums[l]);
24            }
25            dq.push_back(i);
26            
27            // Shrink the window from the right if operations exceed k
28            while (cost > k) {
29                cost -= nums[dq.front()] - nums[j];
30                if (dq.front() == j) {
31                    dq.pop_front();
32                }
33                --j;
34            }
35            
36            // All subarrays starting at i and ending between i and j are valid
37            ans += (j - i + 1);
38        }
39        
40        return ans;
41    }
42};
43