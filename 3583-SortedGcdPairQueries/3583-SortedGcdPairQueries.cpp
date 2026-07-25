// Last updated: 7/25/2026, 4:13:12 PM
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        // cnt[d] = numbers divisible by d
        vector<int> cnt(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            for (int k = d; k <= mx; k += d)
                cnt[d] += freq[k];
        }

        // pairs[g] = pairs with gcd exactly g
        vector<long long> pairs(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            long long c = cnt[g];
            pairs[g] = c * (c - 1) / 2;
            for (int k = g + g; k <= mx; k += g)
                pairs[g] -= pairs[k];
        }

        // prefix[g] = pairs with gcd <= g
        vector<long long> prefix(mx + 1, 0);
        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + pairs[g];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};