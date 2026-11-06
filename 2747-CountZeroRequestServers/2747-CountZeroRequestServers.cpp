// Last updated: 11/6/2026, 12:10:12 PM
1#include <vector>
2#include <algorithm>
3
4using namespace std;
5
6class Solution {
7public:
8    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
9        int numQueries = queries.size();
10        vector<int> result(numQueries);
11        
12        // 1. Store queries with their original index to preserve output order
13        // Pair format: {query_time, original_index}
14        vector<pair<int, int>> sortedQueries(numQueries);
15        for (int i = 0; i < numQueries; ++i) {
16            sortedQueries[i] = {queries[i], i};
17        }
18        
19        // 2. Sort logs by their timestamp (index 1) and queries by their execution time
20        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
21            return a[1] < b[1];
22        });
23        sort(sortedQueries.begin(), sortedQueries.end());
24        
25        // 3. Sliding window setup
26        // Using a frequency vector tracking servers 1-indexed (size n + 1)
27        vector<int> serverCount(n + 1, 0); 
28        int uniqueServersInWindow = 0;
29        int left = 0;
30        int right = 0;
31        int m = logs.size();
32        
33        // 4. Process each query in chronological order
34        for (const auto& [queryTime, originalIndex] : sortedQueries) {
35            int leftBound = queryTime - x;
36            int rightBound = queryTime;
37            
38            // Expand window to include logs up to the right bound
39            while (right < m && logs[right][1] <= rightBound) {
40                int serverId = logs[right][0];
41                if (serverCount[serverId] == 0) {
42                    uniqueServersInWindow++;
43                }
44                serverCount[serverId]++;
45                right++;
46            }
47            
48            // Shrink window to remove logs before the left bound
49            while (left < m && logs[left][1] < leftBound) {
50                int serverId = logs[left][0];
51                serverCount[serverId]--;
52                if (serverCount[serverId] == 0) {
53                    uniqueServersInWindow--;
54                }
55                left++;
56            }
57            
58            // The answer is total servers minus the active servers in the current window
59            result[originalIndex] = n - uniqueServersInWindow;
60        }
61        
62        return result;
63    }
64};
65