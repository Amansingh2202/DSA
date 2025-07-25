class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end()); 

        vector<pair<int, int>> q;
        for (int i = 0; i < queries.size(); ++i) { 
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end()); 

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; 
        vector<int> res(queries.size()); 
        int i = 0; 

        for (auto [query, idx] : q) { 
            while (i < intervals.size() && intervals[i][0] <= query) { 
                int l = intervals[i][0], r = intervals[i][1];
                if (r >= query) {
                    minHeap.push({r - l + 1, r});
                }
                i++;
            }

            while (!minHeap.empty() && minHeap.top().second < query) { 
                minHeap.pop();
            }

            res[idx] = minHeap.empty() ? -1 : minHeap.top().first; 
        }

        return res; 
    }
};
