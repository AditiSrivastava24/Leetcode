// Last updated: 11/3/2026, 10:16:32 PM
1class Solution {
2public:
3    int minMoves(vector<int>& nums) {
4        int n = nums.size();
5        int max_val = nums[0];
6        long long total_sum = 0;
7        
8        for (int num : nums) {
9            if (num > max_val) {
10                max_val = num;
11            }
12            total_sum += num;
13        }
14        
15        return (long long)max_val * n - total_sum;
16    }
17};
18