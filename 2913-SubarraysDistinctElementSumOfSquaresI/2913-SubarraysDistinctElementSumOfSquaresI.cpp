// Last updated: 10/19/2026, 12:51:27 PM
#include <vector>
#include <unordered_set>

class Solution {
public:
    int sumCounts(std::vector<int>& nums) {
        int totalSumOfSquares = 0;
        int n = nums.size();
        
        // Loop through each possible starting index of a subarray
        for (int i = 0; i < n; ++i) {
            std::unordered_set<int> distinctElements;
            
            // Expand the subarray from index i to j
            for (int j = i; j < n; ++j) {
                distinctElements.insert(nums[j]);
                
                // Get the count of distinct elements in the current subarray nums[i...j]
                int distinctCount = distinctElements.size();
                
                // Add its square to the total answer
                totalSumOfSquares += (distinctCount * distinctCount);
            }
        }
        
        return totalSumOfSquares;
    }
};
