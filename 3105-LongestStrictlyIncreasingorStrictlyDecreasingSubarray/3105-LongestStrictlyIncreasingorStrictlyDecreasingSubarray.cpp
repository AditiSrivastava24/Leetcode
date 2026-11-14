// Last updated: 11/15/2026, 12:03:12 AM
1#include <vector>
2#include <algorithm>
3
4using namespace std;
5
6class Solution {
7public:
8    int longestMonotonicSubarray(vector<int>& nums) {
9        int maxLen = 1;
10        int inc = 1;
11        int dec = 1;
12        
13        for (int i = 1; i < nums.size(); ++i) {
14            if (nums[i] > nums[i - 1]) {
15                inc++;
16                dec = 1;
17            } else if (nums[i] < nums[i - 1]) {
18                dec++;
19                inc = 1;
20            } else {
21                inc = 1;
22                dec = 1;
23            }
24            maxLen = max({maxLen, inc, dec});
25        }
26        
27        return maxLen;
28    }
29};
30