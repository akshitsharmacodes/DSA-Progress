class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int maxi_profit = 0;

        for (int i = 1; i < n; i++) {
            int profit = prices[i] - buy;

            maxi_profit = max(profit, maxi_profit);
            buy = min(buy, prices[i]);
        }

        return maxi_profit;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna