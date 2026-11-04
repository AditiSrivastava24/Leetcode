// Last updated: 11/4/2026, 12:29:31 PM
1#include <vector>
2#include <set>
3#include <algorithm>
4#include <climits>
5
6using namespace std;
7
8class Solution {
9public:
10    long long minOperations(vector<int>& nums, int x, int k) {
11        // Step 1: Precompute the minimum operations required for each size-x window
12        const vector<long long> minOps = getMinOps(nums, x);
13        
14        // Step 2: Run Skip-or-Take DP to find the minimum cost for k non-overlapping windows
15        vector<vector<long long>> mem(nums.size() + 1, vector<long long>(k + 1, -1));
16        return solveDP(nums, x, 0, k, minOps, mem);
17    }
18
19private:
20    static constexpr long long kInf = LLONG_MAX / 2;
21
22    long long solveDP(const vector<int>& nums, int x, int i, int k, 
23                      const vector<long long>& minOps, vector<vector<long long>>& mem) {
24        // Base case: successfully picked k subarrays
25        if (k == 0) return 0;
26        // Base case: out of bounds but still need to pick subarrays
27        if (i >= nums.size()) return kInf;
28        // Return cached result if already calculated
29        if (mem[i][k] != -1) return mem[i][k];
30
31        // Option 1: Skip the current index
32        long long skip = solveDP(nums, x, i + 1, k, minOps, mem);
33
34        // Option 2: Pick the size-x window starting at index i (if valid)
35        long long pick = kInf;
36        if (i + x <= nums.size()) {
37            pick = minOps[i] + solveDP(nums, x, i + x, k - 1, minOps, mem);
38        }
39
40        return mem[i][k] = min(skip, pick);
41    }
42
43    vector<long long> getMinOps(const vector<int>& nums, int x) {
44        vector<long long> minOps;
45        multiset<int> lower; // Stores the lower half of numbers (max-heap style via rbegin)
46        multiset<int> upper; // Stores the upper half of numbers (min-heap style via begin)
47        long long lowerSum = 0;
48        long long upperSum = 0;
49
50        for (int i = 0; i < nums.size(); ++i) {
51            // Insert current element into the appropriate multiset
52            if (lower.empty() || nums[i] <= *lower.rbegin()) {
53                lower.insert(nums[i]);
54                lowerSum += nums[i];
55            } else {
56                upper.insert(nums[i]);
57                upperSum += nums[i];
58            }
59
60            // Remove the element sliding out of the window
61            if (i >= x) {
62                int outNum = nums[i - x];
63                if (auto it = lower.find(outNum); it != lower.end()) {
64                    lower.erase(it);
65                    lowerSum -= outNum;
66                } else {
67                    upper.erase(upper.find(outNum));
68                    upperSum -= outNum;
69                }
70            }
71
72            // Rebalance multisets so that: |lower| >= |upper| and |lower| - |upper| <= 1
73            if (lower.size() < upper.size()) {
74                int val = *upper.begin();
75                upper.erase(upper.begin());
76                lower.insert(val);
77                upperSum -= val;
78                lowerSum += val;
79            } else if (lower.size() - upper.size() > 1) {
80                int val = *lower.rbegin();
81                lower.erase(prev(lower.end()));
82                upper.insert(val);
83                lowerSum -= val;
84                upperSum += val;
85            }
86
87            // If the window is complete, calculate the cost to change all elements to the median
88            if (i >= x - 1) {
89                long long median = *lower.rbegin();
90                long long ops = (median * lower.size() - lowerSum) + (upperSum - median * upper.size());
91                minOps.push_back(ops);
92            }
93        }
94        return minOps;
95    }
96};
97