// Last updated: 7/15/2026, 6:36:48 PM
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = n + 2;
        int size = 2 * n + 5;

        vector<int> bit(size + 1, 0);

        auto add = [&](int idx) {
            while (idx <= size) {
                bit[idx]++;
                idx += idx & -idx;
            }
        };

        auto sum = [&](int idx) {
            int res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        };

        long long ans = 0;
        int pref = 0;

        add(pref + offset);

        for (int x : nums) {
            if (x == target) pref++;
            else pref--;

            ans += sum(pref + offset - 1);
            add(pref + offset);
        }

        return ans;
    }
};