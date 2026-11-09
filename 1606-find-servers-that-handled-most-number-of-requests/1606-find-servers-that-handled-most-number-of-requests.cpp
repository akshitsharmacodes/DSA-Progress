class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> avail;
        for (int i = 0; i < k; i++) avail.insert(avail.end(), i);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;
        vector<int> cnt(k, 0);
        int n = arrival.size();
        for (int i = 0; i < n; i++) {
            long long t = arrival[i];
            while (!busy.empty() && busy.top().first <= t) {
                avail.insert(busy.top().second);
                busy.pop();
            }
            if (avail.empty()) continue;
            auto it = avail.lower_bound(i % k);
            if (it == avail.end()) it = avail.begin();
            int s = *it;
            avail.erase(it);
            cnt[s]++;
            busy.emplace(t + load[i], s);
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) if (cnt[i] == mx) ans.push_back(i);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna