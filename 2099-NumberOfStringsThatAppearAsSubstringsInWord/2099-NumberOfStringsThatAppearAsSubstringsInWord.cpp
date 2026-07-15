// Last updated: 7/15/2026, 6:37:03 PM
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for (string p : patterns) {
            if (word.find(p) != string::npos) {
                count++;
            }
        }

        return count;
    }
};