// Last updated: 7/22/2026, 11:24:47 PM
1class Solution {
2public:
3    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
4        int n = s.length();
5        int total_ones = 0;
6        for (char c : s) {
7            if (c == '1') total_ones++;
8        }
9        
10        vector<int> type;
11        vector<int> start;
12        vector<int> end_idx;
13        
14        for (int i = 0; i < n; ) {
15            int j = i;
16            while (j < n && s[j] == s[i]) {
17                j++;
18            }
19            type.push_back(s[i] - '0');
20            start.push_back(i);
21            end_idx.push_back(j - 1);
22            i = j;
23        }
24        
25        int N = type.size();
26        
27        vector<int> pos_to_seg(n);
28        for (int i = 0; i < N; i++) {
29            for (int j = start[i]; j <= end_idx[i]; j++) {
30                pos_to_seg[j] = i; 
31            }
32        }
33        
34        vector<int> ans(N, 0);
35        for (int i = 1; i < N - 1; i++) {
36            if (type[i] == 1) {
37                ans[i] = (end_idx[i - 1] - start[i - 1] + 1) + (end_idx[i + 1] - start[i + 1] + 1);
38            }
39        }
40        
41        vector<int> log_table(N + 1, 0);
42        for (int i = 2; i <= N; i++) {
43            log_table[i] = log_table[i / 2] + 1;
44        }
45        
46        int K = log_table[N] + 1;
47        vector<vector<int>> st(K, vector<int>(N, 0));
48        
49        for (int i = 0; i < N; i++) {
50            st[0][i] = ans[i];
51        }
52        
53        for (int j = 1; j < K; j++) {
54            for (int i = 0; i + (1 << j) <= N; i++) {
55                st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
56            }
57        }
58        
59        auto queryRMQ = [&](int L_idx, int R_idx) {
60            if (L_idx > R_idx) return 0;
61            int j = log_table[R_idx - L_idx + 1];
62            return max(st[j][L_idx], st[j][R_idx - (1 << j) + 1]);
63        };
64        
65        auto eval = [&](int i, int L, int R, int segL, int segR) {
66            if (i <= segL || i >= segR) return 0;
67            if (type[i] == 0) return 0;
68            
69            int left_len = 0;
70            if (i - 1 == segL) left_len = max(0, end_idx[i - 1] - L + 1);
71            else left_len = end_idx[i - 1] - start[i - 1] + 1;
72            
73            int right_len = 0;
74            if (i + 1 == segR) right_len = max(0, R - start[i + 1] + 1);
75            else right_len = end_idx[i + 1] - start[i + 1] + 1;
76            
77            return left_len + right_len;
78        };
79        
80        vector<int> res;
81        
82        for (const auto& q : queries) {
83            int L = q[0];
84            int R = q[1];
85            
86            int segL = pos_to_seg[L];
87            int segR = pos_to_seg[R];
88            
89            if (segR - segL < 2) {
90                res.push_back(total_ones);
91                continue;
92            }
93            
94            int max_gain = 0;
95            max_gain = max(max_gain, eval(segL + 1, L, R, segL, segR));
96            max_gain = max(max_gain, eval(segR - 1, L, R, segL, segR));
97            
98            if (segL + 2 <= segR - 2) {
99                max_gain = max(max_gain, queryRMQ(segL + 2, segR - 2));
100            }
101            
102            res.push_back(total_ones + max_gain);
103        }
104        
105        return res;
106    }
107};