// Last updated: 10/6/2026, 4:29:22 PM
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current = "";
        backtrack(result, current, n, n);
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, std::string& current, int open, int close) {
        // Base Case: No more brackets left to add
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }

        // Rule 1: We can always add an open parenthesis if we have any left
        if (open > 0) {
            current.push_back('(');
            backtrack(result, current, open - 1, close);
            current.pop_back(); // Backtrack
        }

        // Rule 2: We can only add a close parenthesis if it matches an open one
        if (close > open) {
            current.push_back(')');
            backtrack(result, current, open, close - 1);
            current.pop_back(); // Backtrack
        }
    }
};
