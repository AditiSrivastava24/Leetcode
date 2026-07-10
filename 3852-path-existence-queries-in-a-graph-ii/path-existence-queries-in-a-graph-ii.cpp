class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<pair<int,int>> arr;
        arr.reserve(n);

        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> pos(n);
        vector<int> compPos(n);

        int cid = 0;
        for (int i = 0; i < n; i++) {
            pos[arr[i].second] = i;
            if (i > 0 && arr[i].first - arr[i - 1].first > maxDiff)
                cid++;
            compPos[arr[i].second] = cid;
        }

        vector<int> far(n);
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j + 1 < n && arr[j + 1].first - arr[i].first <= maxDiff)
                j++;
            far[i] = j;
        }

        const int LOG = 18;
        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = far[i];

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (compPos[u] != compPos[v]) {
                ans.push_back(-1);
                continue;
            }

            int a = pos[u];
            int b = pos[v];

            if (a > b)
                swap(a, b);

            int cur = a;
            int dist = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < b) {
                    cur = up[k][cur];
                    dist += (1 << k);
                }
            }

            ans.push_back(dist + 1);
        }

        return ans;
    }
};