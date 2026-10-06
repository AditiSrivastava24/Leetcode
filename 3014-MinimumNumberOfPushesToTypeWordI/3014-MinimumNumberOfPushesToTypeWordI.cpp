// Last updated: 10/6/2026, 4:27:45 PM
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int minimumPushes(std::string word) {
        std::vector<int> counts(26, 0);
        for (char c : word) {
            counts[c - 'a']++;
        }
        
        std::sort(counts.rbegin(), counts.rend());
        
        int totalPushes = 0;
        for (int i = 0; i < 26 && counts[i] > 0; ++i) {
            totalPushes += counts[i] * (i / 8 + 1);
        }
        
        return totalPushes;
    }
};
