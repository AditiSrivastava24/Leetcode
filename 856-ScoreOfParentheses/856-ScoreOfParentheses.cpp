// Last updated: 10/6/2026, 4:29:03 PM
class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int depth = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                // If we find a core "()", add its value based on current depth
                if (s[i - 1] == '(') {
                    score += 1 << depth; // 1 << depth is equivalent to 2^depth
                }
            }
        }
        
        return score;
    }
};
