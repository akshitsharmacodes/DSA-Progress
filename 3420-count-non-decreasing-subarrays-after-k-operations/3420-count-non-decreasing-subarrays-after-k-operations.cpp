class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nge(n, n);
        {
            vector<int> st;
            for (int i = n - 1; i >= 0; --i) {
                while (!st.empty() && nums[st.back()] <= nums[i]) st.pop_back();
                nge[i] = st.empty() ? n : st.back();
                st.push_back(i);
            }
        }
        deque<int> dq; // prefix-max leaders of window [l, r], front = l
        long long cost = 0, ans = 0;
        int r = n - 1;
        for (int l = n - 1; l >= 0; --l) {
            while (!dq.empty() && nums[dq.front()] <= nums[l]) {
                int j = dq.front(); dq.pop_front();
                int e = min(nge[j], r + 1) - 1;
                cost += (long long)(nums[l] - nums[j]) * (e - j + 1);
            }
            dq.push_front(l);
            while (cost > k) {
                cost -= nums[dq.back()] - nums[r];
                if (dq.back() == r) dq.pop_back();
                --r;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna