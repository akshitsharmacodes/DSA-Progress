
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n + 1, 0);
        vector<int> suffMin(n + 1, INT_MAX);
        vector<int> prefDrop(n, 0);

        // Prefix maximum
        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        // Suffix minimum
        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        // Count adjacent descents
        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1]
                        + (nums[i - 1] > nums[i]);
        }

        int ans = 0;

        // Check every divisor of n
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;

            for (int i = 0; i < n; i += k) {
                int r = i + k - 1;

                // Descents inside the block
                int drops = prefDrop[r] - prefDrop[i];

                // Circular edge: last element -> first
                if (nums[r] > nums[i]) {
                    drops++;
                }

                // A block must be cyclically sortable
                if (drops > 1) {
                    valid = false;
                    break;
                }

                // Earlier elements must not exceed
                // any element in the remaining suffix
                if (prefMax[i] > suffMin[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna