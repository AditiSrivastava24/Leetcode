// Last updated: 10/19/2026, 12:51:55 PM
#include <vector>

class Solution {
public:
    std::vector<int> targetIndices(std::vector<int>& nums, int target) {
        int lessThanTarget = 0;
        int targetCount = 0;
        
        // Single pass to gather counts
        for (int num : nums) {
            if (num < target) {
                lessThanTarget++;
            } else if (num == target) {
                targetCount++;
            }
        }
        
        // Generate the sequence of target indices
        std::vector<int> result;
        for (int i = 0; i < targetCount; ++i) {
            result.push_back(lessThanTarget + i);
        }
        
        return result;
    }
};
