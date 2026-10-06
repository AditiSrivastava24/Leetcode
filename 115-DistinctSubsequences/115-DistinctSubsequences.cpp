// Last updated: 10/6/2026, 4:29:14 PM
#include <string>
#include <vector>

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int m = s.length();
        int n = t.length();
        
        // dp[j] stores the number of distinct subsequences of t[0...j-1] in s
        // We use unsigned long long to prevent intermediate integer overflow
        std::vector<unsigned long long> dp(n + 1, 0);
        
        // Base case: An empty string t is a subsequence of any prefix of s exactly once
        dp[0] = 1; 
        
        for (int i = 1; i <= m; ++i) {
            // Traverse backwards to use values from the previous row/iteration
            for (int j = n; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
                // If s[i-1] != t[j-1], dp[j] remains the same (dp[j] = dp[j])
            }
        }
        
        return (int)dp[n];
    }
};
