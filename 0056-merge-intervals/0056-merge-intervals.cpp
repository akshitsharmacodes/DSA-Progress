class Solution { 
public: 
    vector<vector<int>> merge(vector<vector<int>>& intervals) { 
        int n = intervals.size(); 
 
        sort(intervals.begin(), intervals.end()); 
 
        vector<vector<int>> ans; 
 
        for (int i = 0; i < n; i++) { 
            if(ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        } 
 
        return ans; 
    } 
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna