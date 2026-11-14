
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int k = l; k <= r; k++) {
            int sum = 0;

            // Calculate initial window sum
            for (int i = 0; i < k; i++) {
                sum += nums[i];
            }

            if (sum > 0) {
                ans = min(ans, sum);
            }

            // Slide the window
            for (int i = k; i < n; i++) {
                sum += nums[i] - nums[i - k];

                if (sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna