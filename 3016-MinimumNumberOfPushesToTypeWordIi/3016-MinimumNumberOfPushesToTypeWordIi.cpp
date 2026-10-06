// Last updated: 10/6/2026, 4:27:39 PM
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int minimumPushes(std::string word) {
        std::vector<int> count(26, 0);
        for (char ch : word) {
            count[ch - 'a']++;
        }
        
        std::sort(count.rbegin(), count.rend());
        
        int total_pushes = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] == 0) break;
            int multiplier = (i / 8) + 1;
            total_pushes += count[i] * multiplier;
        }
        
        return total_pushes;
    }
};
