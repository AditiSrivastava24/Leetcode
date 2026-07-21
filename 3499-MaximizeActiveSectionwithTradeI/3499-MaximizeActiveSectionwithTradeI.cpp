// Last updated: 7/21/2026, 9:37:49 PM
1class Solution {
2public:
3    int maxActiveSectionsAfterTrade(string s) {
4        int ones = 0;
5        for (char c : s)
6            if (c == '1')
7                ones++;
8
9        string t = "1" + s + "1";
10        int n = t.size();
11
12        vector<pair<char, int>> groups;
13
14        for (int i = 0; i < n;) {
15            int j = i;
16            while (j < n && t[j] == t[i]) j++;
17            groups.push_back({t[i], j - i});
18            i = j;
19        }
20
21        int ans = ones;
22
23        for (int i = 1; i + 1 < groups.size(); i++) {
24            if (groups[i].first == '1' &&
25                groups[i - 1].first == '0' &&
26                groups[i + 1].first == '0') {
27
28                ans = max(ans,
29                          ones + groups[i - 1].second + groups[i + 1].second);
30            }
31        }
32
33        return ans;
34    }
35};