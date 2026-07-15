// Last updated: 7/15/2026, 6:36:56 PM
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums) freq[x]++;

        int ans = 1;

        // Special case for 1
        if (freq.count(1)) {
            int c = freq[1];
            ans = max(ans, c % 2 == 1 ? c : c - 1);
        }

        for (auto &p : freq) {
            long long x = p.first;
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (true) {
                if (!freq.count(cur)) {
                    len--;
                    break;
                }

                if (freq[cur] >= 2) {
                    len += 2;

                    if (cur > 1000000000LL / cur) {
                        len--;
                        break;
                    }

                    cur = cur * cur;
                } 
                else {
                    len += 1;
                    break;
                }
            }

            ans = max(ans, len);
        }

        return ans;
    }
};