
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        long long odd = 0;
        long long even = 1;
        long long ans = 0;

        int parity = 0;

        for (int num : arr) {
            parity ^= (num & 1);

            if (parity == 1) {
                ans = (ans + even) % MOD;
                odd++;
            } 
            else {
                ans = (ans + odd) % MOD;
                even++;
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna