
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        // Square every element
        for (int& x : nums) {
            x = x * x;
        }

        // Sort squared values
        sort(nums.begin(), nums.end());

        long long ans = 0;
        int half = n / 2;

        // Subtract the smallest half
        for (int i = 0; i < half; i++) {
            ans -= nums[i];
        }

        // Add the remaining larger squares
        for (int i = half; i < n; i++) {
            ans += nums[i];
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna