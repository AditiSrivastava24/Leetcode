// Last updated: 10/6/2026, 4:29:18 PM
#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> stk;
        stk.push(-1); // Base indicator for length calculation
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else { // s[i] == ')'
                stk.pop();
                if (stk.empty()) {
                    // If empty, this ')' acts as a new boundary line
                    stk.push(i);
                } else {
                    // Valid length is current index minus the top element index
                    maxLen = std::max(maxLen, i - stk.top());
                }
            }
        }
        return maxLen;
    }
};
