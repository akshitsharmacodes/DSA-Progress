
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        int target = (x + 1) / 2;

        auto rebalance = [&]() {
            while (low.size() > target) {
                int val = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= val;

                high.insert(val);
                sumHigh += val;
            }

            while (low.size() < target) {
                int val = *high.begin();
                high.erase(high.begin());
                sumHigh -= val;

                low.insert(val);
                sumLow += val;
            }
        };

        auto add = [&](int val) {
            if (low.empty()) {
                if (high.empty() || val <= *high.begin()) {
                    low.insert(val);
                    sumLow += val;
                } else {
                    high.insert(val);
                    sumHigh += val;
                }
            }
            else if (val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            } else {
                high.insert(val);
                sumHigh += val;
            }
        };

        auto remove = [&](int val) {
            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }
        };

        auto getCost = [&]() -> long long {
            long long median = *low.rbegin();

            return median * (long long)low.size() - sumLow
                 + sumHigh - median * (long long)high.size();
        };

        // Calculate costs of all windows
        int m = n - x + 1;
        vector<long long> cost(m);

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        rebalance();

        for (int i = 0; i < m; i++) {
            cost[i] = getCost();

            if (i + 1 < m) {
                remove(nums[i]);
                add(nums[i + x]);
                rebalance();
            }
        }

        // DP with space optimization
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                // Skip current element
                curr[i] = curr[i - 1];

                // Select a window ending at i-1
                if (i >= x) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna