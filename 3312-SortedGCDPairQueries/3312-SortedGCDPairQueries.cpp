// Last updated: 7/17/2026, 6:48:36 PM
1class Solution {
2public:
3    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
4        int mx = *max_element(nums.begin(), nums.end());
5
6        vector<int> freq(mx + 1, 0);
7        for (int x : nums) freq[x]++;
8
9        // cnt[d] = numbers divisible by d
10        vector<int> cnt(mx + 1, 0);
11        for (int d = 1; d <= mx; d++) {
12            for (int k = d; k <= mx; k += d)
13                cnt[d] += freq[k];
14        }
15
16        // pairs[g] = pairs with gcd exactly g
17        vector<long long> pairs(mx + 1, 0);
18
19        for (int g = mx; g >= 1; g--) {
20            long long c = cnt[g];
21            pairs[g] = c * (c - 1) / 2;
22            for (int k = g + g; k <= mx; k += g)
23                pairs[g] -= pairs[k];
24        }
25
26        // prefix[g] = pairs with gcd <= g
27        vector<long long> prefix(mx + 1, 0);
28        for (int g = 1; g <= mx; g++)
29            prefix[g] = prefix[g - 1] + pairs[g];
30
31        vector<int> ans;
32
33        for (long long q : queries) {
34            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
35            ans.push_back(g);
36        }
37
38        return ans;
39    }
40};