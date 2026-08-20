class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int prev_sum = 0;
        int new_sum;
        vector<int> final;
        for(int i=0; i<n; i++){
            new_sum=nums[i]+prev_sum;
            prev_sum=new_sum;
            final.push_back(new_sum);
        }
        return final;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna