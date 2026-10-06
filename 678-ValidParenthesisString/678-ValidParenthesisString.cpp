// Last updated: 10/6/2026, 4:29:06 PM
#include <string>
#include <algorithm>

class Solution {
public:
    bool checkValidString(std::string s) {
        int minOpen = 0;
        int maxOpen = 0;

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else { // c == '*'
                minOpen--; // If treated as ')'
                maxOpen++; // If treated as '('
            }

            // If maxOpen is negative, it means even if all '*' were treated 
            // as '(', we still have too many closing brackets ')'
            if (maxOpen < 0) return false;

            // minOpen cannot drop below 0 because we can choose to treat 
            // excess '*' as empty strings instead of ')'
            if (minOpen < 0) minOpen = 0;
        }

        // The string is valid if it's possible to end up with 0 open brackets
        return minOpen == 0;
    }
};
