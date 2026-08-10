// Last updated: 8/10/2026, 3:36:10 PM
#include <vector>
#include <algorithm>

class Solution {
public:
    bool predictTheWinner(std::vector<int>& nums) {
        int n = nums.size();
        // dp[j] will store the max score difference for subarray nums[i...j]
        std::vector<int> dp = nums; 
        
        // Loop through all possible lengths of subarrays
        for (int diff = 1; diff < n; diff++) {
            for (int j = n - 1; j - diff >= 0; j--) {
                int i = j - diff;
                // dp[j] represents pick_left, dp[j-1] represents pick_right
                dp[j] = std::max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        
        // Player 1 wins if the final score difference for range [0...n-1] is non-negative
        return dp[n - 1] >= 0;
    }
};
