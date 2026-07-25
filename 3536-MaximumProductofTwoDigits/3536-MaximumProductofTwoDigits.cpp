// Last updated: 7/25/2026, 4:03:42 PM
1class Solution {
2public:
3    int maxProduct(int n) {
4        int a = 0, b = 0;
5        while (n > 0) {
6            int x = n % 10;
7            if (x > a) {
8                b = a;
9                a = x;
10            } else if (x > b) {
11                b = x;
12            }
13            n /= 10;
14        }
15        return a * b;
16    }
17};
18