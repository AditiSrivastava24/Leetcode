// Last updated: 7/16/2026, 4:14:57 PM
1class Solution {
2public:
3    long long gcdSum(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<int> pref(n);
7        int mx = 0;
8
9        for (int i = 0; i < n; i++) {
10            mx = max(mx, nums[i]);
11            pref[i] = gcd(nums[i], mx);
12        }
13
14        sort(pref.begin(), pref.end());
15
16        long long ans = 0;
17        int l = 0, r = n - 1;
18
19        while (l < r) {
20            ans += gcd(pref[l], pref[r]);
21            l++;
22            r--;
23        }
24
25        return ans;
26    }
27};