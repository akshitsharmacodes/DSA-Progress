class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> ans = {-1, -1};

        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;

        int first = -1;
        int last = -1;

        int minDist = INT_MAX;
        int maxDist = -1;

        while (curr->next != nullptr) {

            ListNode* next = curr->next;

            // Check if curr is a critical point
            bool isMax = (curr->val > prev->val && curr->val > next->val);
            bool isMin = (curr->val < prev->val && curr->val < next->val);

            if (isMax || isMin) {

                if (first == -1) {
                    // First critical point
                    first = index;
                } 
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, index - last);

                    // Distance from first critical point
                    maxDist = max(maxDist, index - first);
                }

                last = index;
            }

            prev = curr;
            curr = next;
            index++;
        }

        if (maxDist == -1)
            return {-1, -1};

        return {minDist, maxDist};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna