// Last updated: 10/6/2026, 4:26:21 PM
#include <vector>
#include <algorithm>

class Solution {
public:
    int firstStableIndex(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;

        // Precompute the suffix minimums
        std::vector<int> right(n);
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right[i] = std::min(right[i + 1], nums[i]);
        }

        // Maintain prefix maximum and look for the first stable index
        int left = nums[0];
        for (int i = 0; i < n; ++i) {
            left = std::max(left, nums[i]);
            
            // Check if the instability score meets the condition
            if (left - right[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};
