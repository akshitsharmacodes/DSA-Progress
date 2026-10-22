
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Case 1: Already sorted
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        // Case 2: Length 2 cannot be rearranged
        if (n == 2) {
            return -1;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // Case 3: One operation is enough
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        // Case 4: Three operations are necessary
        if (s[0] == mx && s[n - 1] == mn &&
            count(s.begin(), s.end(), mx) == 1 &&
            count(s.begin(), s.end(), mn) == 1) {
            return 3;
        }

        // Case 5: Two operations are enough
        return 2;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna