// Last updated: 11/16/2026, 11:07:49 PM
1class Solution {
2public:
3    string digitSum(string s, int k) {
4        while (s.size() > k) {
5            string nxt = "";
6            for (int i = 0; i < s.size(); i += k) {
7                int sum = 0;
8                for (int j = i; j < min((int)s.size(), i + k); ++j) {
9                    sum += s[j] - '0';
10                }
11                nxt += to_string(sum);
12            }
13            s = move(nxt);
14        }
15        return s;
16    }
17};
18