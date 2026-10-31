
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {

        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        // memo[cell][direction]
        // -2 = not calculated
        // -1 = invalid
        // otherwise = destination cell ID

        vector<vector<int>> memo(
            m * n, vector<int>(2, -2)
        );

        // dir: 0 = right, 1 = down
        function<int(int, int, int)> resolve =
        [&](int r, int c, int dir) -> int {

            // Out of bounds
            if (r >= m || c >= n)
                return -1;

            int id = r * n + c;

            // Empty cell: final destination
            if (grid[r][c] == 0)
                return id;

            // Already calculated
            if (memo[id][dir] != -2)
                return memo[id][dir];

            int ans;

            // Mirror reflection
            if (dir == 0) {
                ans = resolve(r + 1, c, 1);
            } 
            else {
                ans = resolve(r, c + 1, 0);
            }

            return memo[id][dir] = ans;
        };

        // DP: number of ways to reach each cell
        vector<vector<int>> dp(
            m, vector<int>(n, 0)
        );

        dp[0][0] = 1;

        // Row-major traversal (topological order)
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                // Mirrors are never stopping points
                if (grid[i][j] == 1)
                    continue;

                if (dp[i][j] == 0)
                    continue;

                // Try moving right
                int right = resolve(i, j + 1, 0);

                if (right != -1) {
                    int r = right / n;
                    int c = right % n;

                    dp[r][c] = (
                        dp[r][c] + dp[i][j]
                    ) % MOD;
                }

                // Try moving down
                int down = resolve(i + 1, j, 1);

                if (down != -1) {
                    int r = down / n;
                    int c = down % n;

                    dp[r][c] = (
                        dp[r][c] + dp[i][j]
                    ) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna