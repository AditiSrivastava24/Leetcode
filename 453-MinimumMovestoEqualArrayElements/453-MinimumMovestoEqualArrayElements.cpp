// Last updated: 11/1/2026, 8:42:31 PM
1#include <vector>
2#include <numeric>
3#include <algorithm>
4
5class Solution {
6public:
7    int minMoves(std::vector<int>& nums) {
8        long long sum = 0;
9        int minm = nums[0];
10        
11        for (int num : nums) {
12            sum += num;
13            minm = std::min(minm, num);
14        }
15        
16        return sum - (long long)minm * nums.size();
17    }
18};
19