// Last updated: 7/15/2026, 6:37:14 PM
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        score[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 'X') continue;
                if (i == n - 1 && j == n - 1) continue;

                vector<pair<int,int>> next = {
                    {i + 1, j},     // down
                    {i, j + 1},     // right
                    {i + 1, j + 1}  // diagonal
                };

                int best = -1;
                long long count = 0;

                for (auto [x, y] : next) {
                    if (x < n && y < n && score[x][y] != -1) {
                        if (score[x][y] > best) {
                            best = score[x][y];
                            count = ways[x][y];
                        } else if (score[x][y] == best) {
                            count = (count + ways[x][y]) % MOD;
                        }
                    }
                }

                if (best == -1) continue;

                int val = 0;
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    val = board[i][j] - '0';
                }

                score[i][j] = best + val;
                ways[i][j] = count % MOD;
            }
        }

        if (score[0][0] == -1) return {0, 0};

        return {score[0][0], ways[0][0]};
    }
};