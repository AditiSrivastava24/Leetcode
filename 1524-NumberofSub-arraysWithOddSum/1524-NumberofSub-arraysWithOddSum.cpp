// Last updated: 11/16/2026, 4:46:25 PM
1#include <vector>
2using namespace std;
3
4class Solution {
5public:
6    int numOfSubarrays(vector<int>& arr) {
7        const int MOD = 1e9 + 7;
8        long long ans = 0;
9        int prefixSum = 0;
10        
11        // evenCount starts at 1 to account for an empty prefix (sum = 0)
12        int evenCount = 1; 
13        int oddCount = 0;
14
15        for (int num : arr) {
16            prefixSum += num;
17
18            if (prefixSum % 2 == 1) {
19                // Odd prefix sum minus any previous even prefix sum gives an odd subarray
20                ans = (ans + evenCount) % MOD;
21                oddCount++;
22            } else {
23                // Even prefix sum minus any previous odd prefix sum gives an odd subarray
24                ans = (ans + oddCount) % MOD;
25                evenCount++;
26            }
27        }
28
29        return ans;
30    }
31};
32