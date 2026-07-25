// Last updated: 7/25/2026, 4:13:16 PM
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        return __gcd(mn, mx);
    }
};