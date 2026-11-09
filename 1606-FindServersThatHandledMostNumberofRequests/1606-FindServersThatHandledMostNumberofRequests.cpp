// Last updated: 11/9/2026, 11:54:32 PM
1#include <vector>
2#include <queue>
3#include <set>
4#include <algorithm>
5
6class Solution {
7public:
8    std::vector<int> busiestServers(int k, std::vector<int>& arrival, std::vector<int>& load) {
9        // Track the number of requests handled by each server
10        std::vector<int> request_count(k, 0);
11        
12        // Track available servers by their ID
13        std::set<int> available;
14        for (int i = 0; i < k; ++i) {
15            available.insert(i);
16        }
17        
18        // Min-heap to track busy servers: pair<end_time, server_id>
19        std::priority_queue<std::pair<int, int>, 
20                            std::vector<std::pair<int, int>>, 
21                            std::greater<std::pair<int, int>>> busy;
22        
23        int n = arrival.size();
24        for (int i = 0; i < n; ++i) {
25            int current_time = arrival[i];
26            int current_load = load[i];
27            
28            // 1. Free up servers that finished their tasks before or at the current arrival time
29            while (!busy.empty() && busy.top().first <= current_time) {
30                available.insert(busy.top().second);
31                busy.pop();
32            }
33            
34            // If no servers are available, the request is dropped
35            if (available.empty()) {
36                continue;
37            }
38            
39            // 2. Find the preferred server starting from (i % k)
40            int target = i % k;
41            auto it = available.lower_bound(target);
42            
43            // If not found, wrap around to the beginning of the available servers
44            if (it == available.end()) {
45                it = available.begin();
46            }
47            
48            int assigned_server = *it;
49            
50            // 3. Assign the request to this server
51            request_count[assigned_server]++;
52            busy.push({current_time + current_load, assigned_server});
53            available.erase(it);
54        }
55        
56        // 4. Find the maximum number of requests handled by any server
57        int max_requests = *std::max_element(request_count.begin(), request_count.end());
58        
59        // Collect all servers that achieved the maximum count
60        std::vector<int> result;
61        for (int i = 0; i < k; ++i) {
62            if (request_count[i] == max_requests) {
63                result.push_back(i);
64            }
65        }
66        
67        return result;
68    }
69};
70