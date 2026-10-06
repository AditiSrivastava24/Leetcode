// Last updated: 10/6/2026, 4:28:59 PM
class Solution {
public:
    int minAddToMakeValid(string s) {
        int left_unmatched = 0; // Tracks unmatched '('
        int right_unmatched = 0; // Tracks unmatched ')'

        for (char c : s) {
            if (c == '(') {
                left_unmatched++;
            } else {
                if (left_unmatched > 0) {
                    left_unmatched--; // Match found with a previous '('
                } else {
                    right_unmatched++; // Unmatched ')' needs a preceding '('
                }
            }
        }

        return left_unmatched + right_unmatched;
    }
};