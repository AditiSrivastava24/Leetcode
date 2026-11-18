// Last updated: 11/18/2026, 9:55:49 AM
1class Solution {
2public:
3    int minChanges(string s) {
4        int changes = 0;
5        
6        // Step through the string in pairs of two
7        for (int i = 0; i < s.length(); i += 2) {
8            if (s[i] != s[i + 1]) {
9                changes++;
10            }
11        }
12        
13        return changes;
14    }
15};
16