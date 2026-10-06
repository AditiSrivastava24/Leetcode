// Last updated: 10/6/2026, 4:28:57 PM
#include <vector>
#include <numeric>
#include <string>

class Solution {
public:
    int distinctSubseqII(std::string s) {
        constexpr int kMod = 1'000'000'007;
        
        // endsIn[i] stores the number of unique subsequences that end with ('a' + i)
        std::vector<long> endsIn(26, 0);
        
        for (const char c : s) {
            int current_idx = c - 'a';
            
            // Total unique subsequences found so far
            long total_so_far = 0;
            for (long count : endsIn) {
                total_so_far = (total_so_far + count) % kMod;
            }
            
            // Update the count for the current character: total_so_far + 1 (the character itself)
            endsIn[current_idx] = (total_so_far + 1) % kMod;
        }
        
        // Sum up the counts of subsequences ending in all 26 possible characters
        long ans = 0;
        for (long count : endsIn) {
            ans = (ans + count) % kMod;
        }
        
        return ans;
    }
};
