// Last updated: 11/2/2026, 4:10:40 PM
1class Solution {
2public:
3    int minMoves2(vector<int>& nums) {
4        // Sort the array to find the median
5        sort(nums.begin(), nums.end());
6        
7        // The median element is the optimal meeting point
8        int median = nums[nums.size() / 2];
9        
10        int totalMoves = 0;
11        for (int num : nums) {
12            totalMoves += abs(num - median);
13        }
14        
15        return totalMoves;
16    }
17};
18