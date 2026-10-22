# Last updated: 10/22/2026, 3:08:05 PM
1class Solution:
2    def minOperations(self, nums: list[int]) -> int:
3        n = len(nums)
4        if n <= 1:
5            return 0
6
7        # Locate the position of 0
8        zero = nums.index(0)
9
10        # Check Direction 1: Is it cyclically increasing to the right?
11        is_increasing = True
12        for i in range(n):
13            if nums[(zero + i) % n] != i:
14                is_increasing = False
15                break
16
17        if is_increasing:
18            # Plan A: Rotate left directly -> cost: zero
19            # Plan B: Reverse, rotate, reverse back -> cost: 2 + (n - zero)
20            return min(zero, 2 + n - zero)
21
22        # Check Direction 2: Is it cyclically increasing to the left? (Decreasing sequence)
23        is_decreasing = True
24        for i in range(n):
25            if nums[(zero - i + n) % n] != i:
26                is_decreasing = False
27                break
28
29        if is_decreasing:
30            # Plan A: Rotate left by (zero + 1), then reverse -> cost: zero + 2
31            # Plan B: Reverse first, then rotate left by (n - zero - 1) -> cost: n - zero
32            return min(zero + 2, n - zero)
33
34        # If neither check passes, the array cannot be sorted using these operations
35        return -1
36