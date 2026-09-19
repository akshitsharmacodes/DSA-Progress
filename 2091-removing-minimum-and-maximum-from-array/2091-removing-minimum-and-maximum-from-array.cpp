class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minPos = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxPos = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(minPos, maxPos);
        int right = max(minPos, maxPos);

        return min({
            right + 1,                    // both from left
            n - left,                     // both from right
            (left + 1) + (n - right)      // one from each side
        });
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna