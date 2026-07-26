// Last updated: 7/26/2026, 8:33:59 PM
1#include <vector>
2#include <algorithm>
3#include <climits>
4
5class Solution {
6public:
7    int maximumProduct(std::vector<int>& nums) {
8        // Initialize the three largest values
9        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
10        // Initialize the two smallest values
11        int min1 = INT_MAX, min2 = INT_MAX;
12
13        for (int n : nums) {
14            // Update the three largest values
15            if (n > max1) {
16                max3 = max2;
17                max2 = max1;
18                max1 = n;
19            } else if (n > max2) {
20                max3 = max2;
21                max2 = n;
22            } else if (n > max3) {
23                max3 = n;
24            }
25
26            // Update the two smallest values
27            if (n < min1) {
28                min2 = min1;
29                min1 = n;
30            } else if (n < min2) {
31                min2 = n;
32            }
33        }
34
35        // Return the maximum of the two possible products
36        return std::max(max1 * max2 * max3, min1 * min2 * max1);
37    }
38};
39