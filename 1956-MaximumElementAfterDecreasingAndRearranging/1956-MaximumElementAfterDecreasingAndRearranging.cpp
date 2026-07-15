// Last updated: 7/15/2026, 6:37:04 PM
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int ans = 1;
        arr[0] = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > ans + 1) {
                ans++;
            } else {
                ans = arr[i];
            }
        }

        return ans;
    }
};