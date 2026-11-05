
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1,
                             vector<int>& arr2, int d) {

        sort(arr2.begin(), arr2.end());

        int ans = 0;

        for (int x : arr1) {

            int low = x - d;
            int high = x + d;

            auto it = lower_bound(
                arr2.begin(), arr2.end(), low
            );

            if (it == arr2.end() || *it > high) {
                ans++;
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna