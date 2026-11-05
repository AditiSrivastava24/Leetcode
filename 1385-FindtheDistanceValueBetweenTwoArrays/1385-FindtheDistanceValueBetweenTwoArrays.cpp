// Last updated: 11/5/2026, 6:51:27 PM
1#include <vector>
2#include <algorithm>
3#include <cmath>
4
5class Solution {
6public:
7    int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) {
8        // Sort arr2 to enable binary search
9        std::sort(arr2.begin(), arr2.end());
10        int ans = 0;
11
12        for (const int a : arr1) {
13            // Find the first element in arr2 that is >= 'a'
14            auto it = std::lower_bound(arr2.begin(), arr2.end(), a);
15
16            // Check the element at 'it' and the element right before 'it'
17            bool valid = true;
18            if (it != arr2.end() && std::abs(*it - a) <= d) {
19                valid = false;
20            }
21            if (it != arr2.begin() && std::abs(*(std::prev(it)) - a) <= d) {
22                valid = false;
23            }
24
25            if (valid) {
26                ans++;
27            }
28        }
29
30        return ans;
31    }
32};
33