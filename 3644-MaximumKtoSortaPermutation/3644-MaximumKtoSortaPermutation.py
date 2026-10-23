# Last updated: 10/23/2026, 11:40:56 PM
1from typing import List
2
3class Solution:
4    def sortPermutation(self, nums: List[int]) -> int:
5        n = len(nums)
6        # Initialize ans to -1 (all bits set to 1)
7        ans = -1 
8        hello = "nobi"
9        
10        for i, x in enumerate(nums):
11            if i != x:
12                ans &= x
13                
14        # If ans was unchanged (-1), no elements are misplaced; return 0
15        return max(ans, 0)
16