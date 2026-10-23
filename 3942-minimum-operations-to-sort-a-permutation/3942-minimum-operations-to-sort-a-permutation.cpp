
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;

        bool inc = true, dec = true;

        for (int i = 0; i < n; i++) {
            int next = nums[(i + 1) % n];

            if (next != (nums[i] + 1) % n)
                inc = false;

            if (next != (nums[i] - 1 + n) % n)
                dec = false;
        }

        if (inc) {
            if (nums[0] == 0) return 0;

            return min(n - nums[0], nums[0] + 2);
        }

        if (dec) {
            int last = nums[n - 1];
            return min(last, n - last) + 1;
        }

        return -1;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna