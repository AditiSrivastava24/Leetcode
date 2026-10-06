// Last updated: 10/6/2026, 4:27:57 PM
#include <vector>

class Solution {
private:
    int m, n;
    // mem[i][j][k] stores: -1 (unvisited), 0 (false), 1 (true)
    int mem[101][101][201]; 

    bool dfs(const std::vector<std::vector<char>>& grid, int i, int j, int k) {
        // 1. Out of bounds check
        if (i == m || j == n) return false;

        // Update balance for the current cell
        k += (grid[i][j] == '(') ? 1 : -1;

        // 2. Invalid balance pruning
        // If k < 0, we have an unmatched closing parenthesis.
        // If k > remaining Manhattan distance, we can't close all open brackets.
        if (k < 0 || k > (m - 1 - i) + (n - 1 - j)) return false;

        // 3. Base Case: Reached the bottom-right corner
        if (i == m - 1 && j == n - 1) {
            return k == 0;
        }

        // 4. Memoization lookup
        if (mem[i][j][k] != -1) {
            return mem[i][j][k];
        }

        // 5. Explore path choices: Go Down or Go Right
        bool matchFound = dfs(grid, i + 1, j, k) || dfs(grid, i, j + 1, k);

        return mem[i][j][k] = matchFound;
    }

public:
    bool hasValidPath(std::vector<std::vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Guard clauses for impossible paths
        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        // Initialize memoization array with -1
        std::memset(mem, -1, sizeof(mem));

        return dfs(grid, 0, 0, 0);
    }
};
