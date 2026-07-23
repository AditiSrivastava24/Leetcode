// Last updated: 7/23/2026, 10:35:46 PM
1class Solution {
2public:
3    int uniqueXorTriplets(vector<int>& nums) {
4        const int n = nums.size();
5        if (n == 1) return 1;
6        if (n == 2) return 2;
7        
8        int bits = static_cast<int>(log2(n)) + 1;
9        return 1 << bits;
10    }
11};
12