class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        if (intervals.empty()) return ans;

        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];

        int i = 1;
        while (i < intervals.size()) {
            
            while (i < intervals.size() && end >= intervals[i][0]) {
                end = max(end, intervals[i][1]);
                i++;
            }

        
            ans.push_back({start, end});

        
            if (i < intervals.size()) {
                start = intervals[i][0];
                end = intervals[i][1];
                i++;
            }
        }

    
        if (ans.empty() || ans.back()[1] < start ) {
            ans.push_back({start, end});
        }

        return ans;
    }
};
