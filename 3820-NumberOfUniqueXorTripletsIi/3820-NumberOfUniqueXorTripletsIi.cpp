// Last updated: 7/25/2026, 4:13:07 PM
#include <vector>
#include <algorithm>

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        // The maximum value of nums[i] is 1500. 
        // The maximum possible XOR value using 11 bits is 2047.
        const int MAX_XOR = 2048;
        
        std::vector<bool> has1(MAX_XOR, false);
        std::vector<bool> has2(MAX_XOR, false);
        std::vector<bool> has3(MAX_XOR, false);
        
        // Step 1: Track all unique individual elements
        for (int num : nums) {
            has1[num] = true;
        }
        
        // Step 2: Generate all unique pair XOR combinations
        for (int i = 0; i < MAX_XOR; ++i) {
            if (!has1[i]) continue;
            for (int num : nums) {
                has2[i ^ num] = true;
            }
        }
        
        // Step 3: Generate all unique triplet XOR combinations
        for (int i = 0; i < MAX_XOR; ++i) {
            if (!has2[i]) continue;
            for (int num : nums) {
                has3[i ^ num] = true;
            }
        }
        
        // Step 4: Count the total number of unique triplet outcomes
        int uniqueCount = 0;
        for (int i = 0; i < MAX_XOR; ++i) {
            if (has3[i]) {
                uniqueCount++;
            }
        }
        
        return uniqueCount;
    }
};
