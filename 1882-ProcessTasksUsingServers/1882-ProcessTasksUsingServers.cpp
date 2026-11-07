// Last updated: 11/7/2026, 11:37:14 AM
1#include <vector>
2#include <queue>
3#include <tuple>
4#include <algorithm>
5
6using namespace std;
7
8class Solution {
9public:
10    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
11        int n = servers.size();
12        int m = tasks.size();
13        vector<int> ans(m);
14
15        // Min-heap for idle servers: {weight, index}
16        // Ordered by weight first, then index
17        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> idleServers;
18
19        // Min-heap for busy servers: {free_time, weight, index}
20        // Ordered by free_time first, then weight, then index
21        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busyServers;
22
23        // Initialize all servers as idle at time 0
24        for (int i = 0; i < n; ++i) {
25            idleServers.push({servers[i], i});
26        }
27
28        long long currentTime = 0;
29
30        for (int i = 0; i < m; ++i) {
31            // The task at index i becomes available at time i
32            currentTime = max(currentTime, (long long)i);
33
34            // If no servers are available, fast-forward time to when the earliest server becomes free
35            if (idleServers.empty()) {
36                currentTime = max(currentTime, get<0>(busyServers.top()));
37            }
38
39            // Release all servers that have finished their tasks by the currentTime
40            while (!busyServers.empty() && get<0>(busyServers.top()) <= currentTime) {
41                auto [freeTime, weight, idx] = busyServers.top();
42                busyServers.pop();
43                idleServers.push({weight, idx});
44            }
45
46            // Assign the current task to the best available server
47            auto [weight, idx] = idleServers.top();
48            idleServers.pop();
49
50            ans[i] = idx;
51            
52            // Push the server to the busy heap with its new completion time
53            busyServers.push({currentTime + tasks[i], weight, idx});
54        }
55
56        return ans;
57    }
58};
59