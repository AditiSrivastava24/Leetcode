// Last updated: 10/19/2026, 12:51:29 PM
#include <vector>

class Solution {
public:
    int maxSum(std::vector<int>& nums, int k) {
        constexpr int kMod = 1'000'000'007;
        // nums[i] <= 10^9, which requires up to 30 bits
        constexpr int kMaxBit = 30; 
        
        // Step 1: Count the frequency of set bits (1s) at each bit position
        std::vector<int> bitCount(kMaxBit, 0);
        for (int num : nums) {
            for (int i = 0; i < kMaxBit; ++i) {
                if ((num >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }
        
        long long totalSumOfSquares = 0;
        
        // Step 2: Greedily reconstruct the k largest possible numbers
        for (int step = 0; step < k; ++step) {
            long long currentNum = 0;
            for (int i = 0; i < kMaxBit; ++i) {
                // If a bit is available at position i, pull it into the current number
                if (bitCount[i] > 0) {
                    currentNum |= (1LL << i);
                    bitCount[i]--; // Consume the bit
                }
            }
            // Step 3: Accumulate the square of the reconstructed number
            totalSumOfSquares = (totalSumOfSquares + (currentNum * currentNum)) % kMod;
        }
        
        return totalSumOfSquares;
    }
};
