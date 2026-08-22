class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int count_zero = 0;
        int count_one = 0;
        int count_two = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                count_zero++;
            else if (nums[i] == 1)
                count_one++;
            else
                count_two++;
        }

        int index = 0;

        // Put all 0s
        for (int i = 0; i < count_zero; i++) {
            nums[index++] = 0;
        }

        // Put all 1s
        for (int i = 0; i < count_one; i++) {
            nums[index++] = 1;
        }

        // Put all 2s
        for (int i = 0; i < count_two; i++) {
            nums[index++] = 2;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna