// Last updated: 7/24/2026, 11:32:57 PM
1#include <vector>
2#include <algorithm>
3
4class Solution {
5public:
6    int uniqueXorTriplets(std::vector<int>& nums) {
7        // The maximum value of nums[i] is 1500. 
8        // The maximum possible XOR value using 11 bits is 2047.
9        const int MAX_XOR = 2048;
10        
11        std::vector<bool> has1(MAX_XOR, false);
12        std::vector<bool> has2(MAX_XOR, false);
13        std::vector<bool> has3(MAX_XOR, false);
14        
15        // Step 1: Track all unique individual elements
16        for (int num : nums) {
17            has1[num] = true;
18        }
19        
20        // Step 2: Generate all unique pair XOR combinations
21        for (int i = 0; i < MAX_XOR; ++i) {
22            if (!has1[i]) continue;
23            for (int num : nums) {
24                has2[i ^ num] = true;
25            }
26        }
27        
28        // Step 3: Generate all unique triplet XOR combinations
29        for (int i = 0; i < MAX_XOR; ++i) {
30            if (!has2[i]) continue;
31            for (int num : nums) {
32                has3[i ^ num] = true;
33            }
34        }
35        
36        // Step 4: Count the total number of unique triplet outcomes
37        int uniqueCount = 0;
38        for (int i = 0; i < MAX_XOR; ++i) {
39            if (has3[i]) {
40                uniqueCount++;
41            }
42        }
43        
44        return uniqueCount;
45    }
46};
47