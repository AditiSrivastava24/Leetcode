// Last updated: 10/6/2026, 4:28:31 PM
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(26, 0);

        for(char ch : text) {
            cnt[ch - 'a']++;
        }

        return min({
            cnt['b' - 'a'],
            cnt['a' - 'a'],
            cnt['l' - 'a'] / 2,
            cnt['o' - 'a'] / 2,
            cnt['n' - 'a']
        });
    }
};