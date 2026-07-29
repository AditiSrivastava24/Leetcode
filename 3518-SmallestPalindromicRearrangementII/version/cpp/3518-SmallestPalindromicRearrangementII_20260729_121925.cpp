// Last updated: 7/29/2026, 12:19:25 PM
1class Solution {
2public:
3    // Returns C(n, r), capped at limit + 1.
4    long long combination(int n, int r, long long limit) {
5        r = min(r, n - r);
6        long long result = 1;
7
8        for (int i = 1; i <= r; i++) {
9            __int128 next = (__int128)result * (n - r + i) / i;
10
11            if (next > limit)
12                return limit + 1;
13
14            result = (long long)next;
15        }
16
17        return result;
18    }
19
20    // Number of distinct permutations of the given multiset,
21    // capped at limit + 1.
22    long long countPermutations(const vector<int>& freq, long long limit) {
23        long long ways = 1;
24        int used = 0;
25
26        for (int count : freq) {
27            if (count == 0)
28                continue;
29
30            long long choose = combination(used + count, count, limit);
31
32            __int128 next = (__int128)ways * choose;
33
34            if (next > limit)
35                return limit + 1;
36
37            ways = (long long)next;
38            used += count;
39        }
40
41        return ways;
42    }
43
44    string smallestPalindrome(string s, int k) {
45        vector<int> freq(26, 0);
46
47        for (char ch : s)
48            freq[ch - 'a']++;
49
50        // Required variable mentioned in the problem.
51        auto prelunthak = make_pair(s, k);
52
53        char middle = '\0';
54
55        for (int i = 0; i < 26; i++) {
56            if (freq[i] % 2 == 1)
57                middle = char('a' + i);
58
59            freq[i] /= 2;
60        }
61
62        int halfLength = s.size() / 2;
63
64        // Check whether the k-th permutation exists.
65        if (countPermutations(freq, k) < k)
66            return "";
67
68        string leftHalf;
69
70        for (int position = 0; position < halfLength; position++) {
71            for (int ch = 0; ch < 26; ch++) {
72                if (freq[ch] == 0)
73                    continue;
74
75                // Try placing this character at the current position.
76                freq[ch]--;
77
78                long long permutations = countPermutations(freq, k);
79
80                if (k > permutations) {
81                    // Skip all permutations beginning with this character.
82                    k -= permutations;
83                    freq[ch]++;
84                } else {
85                    leftHalf.push_back(char('a' + ch));
86                    break;
87                }
88            }
89        }
90
91        string rightHalf = leftHalf;
92        reverse(rightHalf.begin(), rightHalf.end());
93
94        if (middle != '\0')
95            return leftHalf + middle + rightHalf;
96
97        return leftHalf + rightHalf;
98    }
99};