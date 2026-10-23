# Last updated: 10/23/2026, 1:04:45 PM
1from typing import List
2
3class Solution:
4    def sortPermutation(self, nums: List[int]) -> int:
5        n = len(nums)
6        # Initialize ans to -1 (all bits set to 1)
7        ans = -1 
8        
9        for i, x in enumerate(nums):
10            if i != x:
11                ans &= x
12                
13        # If ans was unchanged (-1), no elements are misplaced; return 0
14        return max(ans, 0)
15