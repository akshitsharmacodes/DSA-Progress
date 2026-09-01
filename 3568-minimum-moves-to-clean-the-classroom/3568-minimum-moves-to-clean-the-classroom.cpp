class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        vector<vector<int>> id(m, vector<int>(n, -1));

        int k = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = k++;
                }
            }
        }

        int fullMask = (1 << k) - 1;

        // best[r][c][mask] = maximum remaining energy
        // with which we have reached this state.
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        struct Node {
            int r, c;
            int mask;
            int e;
        };

        queue<Node> q;

        best[sr][sc][0] = energy;
        q.push({sr, sc, 0, energy});

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == fullMask)
                    return moves;

                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // Reset energy
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    // Dominance pruning:
                    // If we've already reached this state
                    // with >= energy, this state is useless.
                    if (best[nr][nc][nmask] >= ne)
                        continue;

                    best[nr][nc][nmask] = ne;

                    q.push({nr, nc, nmask, ne});
                }
            }

            moves++;
        }

        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna