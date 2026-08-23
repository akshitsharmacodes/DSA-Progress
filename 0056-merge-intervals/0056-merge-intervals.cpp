class Solution { 
public: 
    vector<vector<int>> merge(vector<vector<int>>& intervals) { 
        int n = intervals.size(); 
 
        sort(intervals.begin(), intervals.end()); 
 
        vector<vector<int>> ans; 
 
        for (int i = 0; i < n; i++) { 
            int start = intervals[i][0]; 
            int end = intervals[i][1]; 
 
            int j = i + 1;
            
            for (; j < n; j++) { 
                if (intervals[j][0] <= end) { 
                    end = max(end, intervals[j][1]); 
                } 
                else { 
                    break; 
                } 
            } 
 
            ans.push_back({start, end}); 

            i = j - 1;
        } 
 
        return ans; 
    } 
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna