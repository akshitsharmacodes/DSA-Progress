class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long both = min<long long>(need1, need2);
        long long c1 = min(cost1, costBoth), c2 = min(cost2, costBoth);
        long long pair = min<long long>((long long)cost1 + cost2, costBoth);
        return both * pair + (need1 - both) * c1 + (need2 - both) * c2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna