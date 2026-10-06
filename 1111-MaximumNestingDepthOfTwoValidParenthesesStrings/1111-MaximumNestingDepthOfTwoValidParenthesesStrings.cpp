// Last updated: 10/6/2026, 4:28:48 PM
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> maxDepthAfterSplit(std::string seq) {
        std::vector<int> ans(seq.size(), 0);
        int depth = 0;
        
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '(') {
                ans[i] = depth % 2;
                depth++;
            } else {
                depth--;
                ans[i] = depth % 2;
            }
        }
        
        return ans;
    }
};
