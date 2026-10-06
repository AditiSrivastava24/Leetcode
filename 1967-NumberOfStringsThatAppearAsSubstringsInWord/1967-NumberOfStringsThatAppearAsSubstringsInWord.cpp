// Last updated: 10/6/2026, 4:28:05 PM
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