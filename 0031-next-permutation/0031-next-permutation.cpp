class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int check = -1;
        int swap_idx;

        
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                check = i - 1;
                break;
            }
        }
         if (check >= 0) {
            swap_idx = n - 1;

            while (nums[swap_idx] <= nums[check]) {
                swap_idx--;
            }

            swap(nums[check], nums[swap_idx]);
        }

        
        reverse(nums.begin() + check + 1, nums.end());
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna