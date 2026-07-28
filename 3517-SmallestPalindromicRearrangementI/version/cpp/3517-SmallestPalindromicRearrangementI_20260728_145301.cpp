// Last updated: 7/28/2026, 2:53:01 PM
1#include <string>
2#include <algorithm>
3
4class Solution {
5public:
6    std::string smallestPalindrome(std::string s) {
7        int n = s.length();
8        // Extract the left half
9        std::string sortedHalf = s.substr(0, n / 2);
10        // Sort it to achieve the smallest lexicographical arrangement
11        std::sort(sortedHalf.begin(), sortedHalf.end());
12        
13        std::string reversedHalf = sortedHalf;
14        std::reverse(reversedHalf.begin(), reversedHalf.end());
15        
16        if (n % 2 != 0) {
17            return sortedHalf + s[n / 2] + reversedHalf;
18        }
19        return sortedHalf + reversedHalf;
20    }
21};
22