
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[j][x] = can we reach the current cell
        // in column j with XOR value x?
        vector<vector<bool>> dp(
            n, vector<bool>(1024, false)
        );

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<bool> curr(1024, false);
                int val = grid[i][j];

                if (i == 0 && j == 0) {
                    curr[val] = true;
                } else {
                    // Reach from above.
                    if (i > 0) {
                        for (int x = 0; x < 1024; x++) {
                            if (dp[j][x]) {
                                curr[x ^ val] = true;
                            }
                        }
                    }

                    // Reach from the left.
                    if (j > 0) {
                        for (int x = 0; x < 1024; x++) {
                            if (dp[j - 1][x]) {
                                curr[x ^ val] = true;
                            }
                        }
                    }
                }

                dp[j] = curr;
            }
        }

        // Find the smallest reachable XOR at the destination.
        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna