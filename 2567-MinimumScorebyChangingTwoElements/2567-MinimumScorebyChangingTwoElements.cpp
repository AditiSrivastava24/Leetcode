// Last updated: 11/19/2026, 7:14:32 PM
1#include <vector>
2#include <algorithm>
3
4using namespace std;
5
6class Solution {
7public:
8    int minimizeSum(vector<int>& nums) {
9        int n = nums.size();
10        sort(nums.begin(), nums.end());
11        
12        // Case 1: Change the two smallest elements (nums[0], nums[1])
13        int opt1 = nums[n - 1] - nums[2];
14        
15        // Case 2: Change the smallest and largest elements (nums[0], nums[n - 1])
16        int opt2 = nums[n - 2] - nums[1];
17        
18        // Case 3: Change the two largest elements (nums[n - 2], nums[n - 1])
19        int opt3 = nums[n - 3] - nums[0];
20        
21        return min({opt1, opt2, opt3});
22    }
23};
24