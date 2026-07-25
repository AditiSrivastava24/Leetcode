// Last updated: 7/25/2026, 4:13:06 PM
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        int bits = static_cast<int>(log2(n)) + 1;
        return 1 << bits;
    }
};
