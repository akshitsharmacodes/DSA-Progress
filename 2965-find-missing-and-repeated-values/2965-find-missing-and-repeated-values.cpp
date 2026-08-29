class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& a) {
        long long n = a.size();
        long long N = n * n;

        long long SN = N * (N + 1) / 2;
        long long S2N = N * (N + 1) * (2 * N + 1) / 6;

        long long S = 0;
        long long S2 = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                S += a[i][j];
                S2 += (long long)a[i][j] * a[i][j];
            }
        }

        // repeated - missing
        long long val1 = S - SN;

        // repeated^2 - missing^2
        long long val2 = S2 - S2N;

        // repeated + missing
        val2 = val2 / val1;

        // repeated
        long long repeated = (val1 + val2) / 2;

        // missing
        long long missing = repeated - val1;

        return {(int)repeated, (int)missing};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna