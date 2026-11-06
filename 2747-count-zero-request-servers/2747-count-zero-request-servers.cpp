class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        int m = logs.size();
        int q = queries.size();

        // Sort logs by time
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        // Store queries with their original indices
        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(q, 0);
        vector<int> cnt(n + 1, 0);

        int left = 0;
        int right = 0;
        int active = 0;

        for (auto [time, index] : sortedQueries) {

            int start = time - x;

            // Expand window: include logs <= time
            while (right < m && logs[right][1] <= time) {

                int id = logs[right][0];

                if (cnt[id] == 0) {
                    active++;
                }

                cnt[id]++;
                right++;
            }

            // Shrink window: remove logs < start
            while (left < right && logs[left][1] < start) {

                int id = logs[left][0];

                cnt[id]--;

                if (cnt[id] == 0) {
                    active--;
                }

                left++;
            }

            // Inactive servers
            ans[index] = n - active;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna