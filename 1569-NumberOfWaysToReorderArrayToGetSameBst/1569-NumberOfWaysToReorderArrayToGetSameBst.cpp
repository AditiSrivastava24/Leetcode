// Last updated: 10/19/2026, 12:52:02 PM
#include <vector>

using namespace std;

class Solution {
private:
    long long MOD = 1e9 + 7;
    vector<vector<long long>> table;

    // Precompute Pascal's Triangle for combination lookup C(n, k)
    void generatePascalTriangle(int n) {
        table.assign(n + 1, vector<long long>(n + 1, 1));
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }
    }

    long long dfs(const vector<int>& nums) {
        if (nums.size() <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];

        // Separate elements into left and right subtrees
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        // Recursive calls for subtrees
        long long leftWays = dfs(left);
        long long rightWays = dfs(right);

        // Total ways for this root = C(L+R, L) * leftWays * rightWays
        long long totalWays = table[left.size() + right.size()][left.size()];
        totalWays = (totalWays * leftWays) % MOD;
        totalWays = (totalWays * rightWays) % MOD;

        return totalWays;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        generatePascalTriangle(n);
        
        // Subtract 1 to exclude the original array arrangement
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};
