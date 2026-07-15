// Last updated: 7/15/2026, 6:36:43 PM
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int m = r - l + 1;

        static int up[2005], down[2005];
        static int newUp[2005], newDown[2005];
        static int prefUp[2006], prefDown[2006];

        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        for (int len = 3; len <= n; len++) {
            prefUp[0] = 0;
            prefDown[0] = 0;

            for (int i = 0; i < m; i++) {
                prefUp[i + 1] = (prefUp[i] + up[i]) % MOD;
                prefDown[i + 1] = (prefDown[i] + down[i]) % MOD;
            }

            for (int i = 0; i < m; i++) {
                newUp[i] = prefDown[i];

                newDown[i] = prefUp[m] - prefUp[i + 1];
                if (newDown[i] < 0) newDown[i] += MOD;
            }

            for (int i = 0; i < m; i++) {
                up[i] = newUp[i];
                down[i] = newDown[i];
            }
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return ans;
    }
};