class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        bool hasOdd = false;

        for (int x : nums1) {
            if (x % 2 == 1) {
                hasOdd = true;
                minOdd = min(minOdd, x);
            }
        }

        // Already all even
        if (!hasOdd) return true;

        // Try making everything odd
        for (int x : nums1) {
            if (x % 2 == 0 && x <= minOdd) {
                return false;
            }
        }

        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna