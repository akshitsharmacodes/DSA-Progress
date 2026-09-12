class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};

        for (int d : digits)
            freq[d]++;

        int ans = 0;

        for (int num = 100; num <= 998; num += 2) {
            int x = num;

            int a = x / 100;        // hundreds
            int b = (x / 10) % 10;  // tens
            int c = x % 10;         // units

            // Need enough copies of each digit
            if (--freq[a] < 0) {
                freq[a]++;
                continue;
            }

            if (--freq[b] < 0) {
                freq[a]++;
                freq[b]++;
                continue;
            }

            if (--freq[c] < 0) {
                freq[a]++;
                freq[b]++;
                freq[c]++;
                continue;
            }

            ans++;

            // Restore frequencies
            freq[a]++;
            freq[b]++;
            freq[c]++;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna