// Last updated: 7/30/2026, 9:13:09 PM
#include <string>
#include <algorithm>

class Solution {
public:
    std::string smallestPalindrome(std::string s) {
        int n = s.length();
        // Extract the left half
        std::string sortedHalf = s.substr(0, n / 2);
        // Sort it to achieve the smallest lexicographical arrangement
        std::sort(sortedHalf.begin(), sortedHalf.end());
        
        std::string reversedHalf = sortedHalf;
        std::reverse(reversedHalf.begin(), reversedHalf.end());
        
        if (n % 2 != 0) {
            return sortedHalf + s[n / 2] + reversedHalf;
        }
        return sortedHalf + reversedHalf;
    }
};
