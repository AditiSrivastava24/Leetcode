// Last updated: 10/19/2026, 12:51:43 PM
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        
        for (int i = 0; i < n; ++i) {
            // Since the problem uses 1-based indexing, 
            // the 1-based position for a 0-indexed 'i' is 'i + 1'
            if (n % (i + 1) == 0) {
                total_sum += nums[i] * nums[i];
            }
        }
        
        return total_sum;
    }
};
