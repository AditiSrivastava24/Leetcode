// Last updated: 7/19/2026, 9:26:06 PM
1class Solution {
2public:
3    string smallestSubsequence(string s) {
4        vector<int> last(26);
5
6        for (int i = 0; i < s.size(); i++)
7            last[s[i] - 'a'] = i;
8
9        vector<bool> used(26, false);
10        string st;
11
12        for (int i = 0; i < s.size(); i++) {
13            char c = s[i];
14
15            if (used[c - 'a'])
16                continue;
17
18            while (!st.empty() &&
19                   st.back() > c &&
20                   last[st.back() - 'a'] > i) {
21
22                used[st.back() - 'a'] = false;
23                st.pop_back();
24            }
25
26            st.push_back(c);
27            used[c - 'a'] = true;
28        }
29
30        return st;
31    }
32};