class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> divs(n + 1);
        for (int d = 1; d <= n; ++d)
            for (int m = 2 * d; m <= n; m += d) divs[m].push_back(d);
        // cost[i][j]: min changes to make s[i..j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1, best = INT_MAX;
                for (int d : divs[len]) {
                    int c = 0;
                    for (int g = 0; g < d && c < best; ++g)
                        for (int l = i + g, r = j - (d - 1 - g); l < r; l += d, r -= d)
                            c += s[l] != s[r];
                    best = min(best, c);
                }
                cost[i][j] = best;
            }
        const int INF = INT_MAX / 2;
        vector<int> prev(n + 1, INF), cur(n + 1);
        prev[0] = 0;
        for (int p = 1; p <= k; ++p) {
            fill(cur.begin(), cur.end(), INF);
            for (int e = 2 * p; e <= n; ++e)
                for (int b = 2 * (p - 1); b + 2 <= e; ++b)
                    if (prev[b] < INF) cur[e] = min(cur[e], prev[b] + cost[b][e - 1]);
            swap(prev, cur);
        }
        return prev[n];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna