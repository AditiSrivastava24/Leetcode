// Last updated: 10/6/2026, 4:28:10 PM
#include <string>
#include <algorithm>

class Solution {
public:
    int maxDepth(std::string s) {
        int max_depth = 0;
        int current_depth = 0;
        
        for (char ch : s) {
            if (ch == '(') {
                current_depth++;
                max_depth = std::max(max_depth, current_depth);
            } else if (ch == ')') {
                current_depth--;
            }
        }
        
        return max_depth;
    }
};
