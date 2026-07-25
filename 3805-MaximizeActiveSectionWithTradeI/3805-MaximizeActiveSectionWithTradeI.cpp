// Last updated: 7/25/2026, 4:13:09 PM
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            if (c == '1')
                ones++;

        string t = "1" + s + "1";
        int n = t.size();

        vector<pair<char, int>> groups;

        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && t[j] == t[i]) j++;
            groups.push_back({t[i], j - i});
            i = j;
        }

        int ans = ones;

        for (int i = 1; i + 1 < groups.size(); i++) {
            if (groups[i].first == '1' &&
                groups[i - 1].first == '0' &&
                groups[i + 1].first == '0') {

                ans = max(ans,
                          ones + groups[i - 1].second + groups[i + 1].second);
            }
        }

        return ans;
    }
};