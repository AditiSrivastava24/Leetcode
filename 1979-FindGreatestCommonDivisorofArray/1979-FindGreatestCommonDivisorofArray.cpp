// Last updated: 7/18/2026, 1:07:00 PM
1class Solution {
2public:
3    int findGCD(vector<int>& nums) {
4        int mn = *min_element(nums.begin(), nums.end());
5        int mx = *max_element(nums.begin(), nums.end());
6
7        return __gcd(mn, mx);
8    }
9};