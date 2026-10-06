// Last updated: 10/6/2026, 4:27:16 PM
#include <string>

class Solution {
public:
    int reverseDegree(std::string s) {
        int total_sum = 0;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            // 'a' = 26, 'b' = 25, ..., 'z' = 1
            int rev_alpha = 26 - (s[i] - 'a'); 
            
            // 1-based indexing for string position
            int string_pos = i + 1; 
            
            total_sum += rev_alpha * string_pos;
        }
        
        return total_sum;
    }
};
