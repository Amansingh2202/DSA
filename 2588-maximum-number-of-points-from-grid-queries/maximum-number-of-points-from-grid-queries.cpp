class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
         int n = grid.size();
        int m = grid[0].size();
        int totalCells = n * m;

        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result(queries.size());
        unordered_map<int, int> queryResult;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({grid[0][0], 0});

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[0][0] = true;

        vector<int> dirX = {-1, 1, 0, 0};
        vector<int> dirY = {0, 0, -1, 1};

        int count = 0, i = 0;

        for (int query : sortedQueries) {
            while (!pq.empty() && pq.top().first < query) {
                auto [val, index] = pq.top();
                pq.pop();
                count++;

                int row = index / m;
                int col = index % m;

                for (int d = 0; d < 4; d++) {
                    int newRow = row + dirX[d];
                    int newCol = col + dirY[d];

                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        pq.push({grid[newRow][newCol], newRow * m + newCol});
                    }
                }
            }
            queryResult[query] = count;
        }

        for (int i = 0; i < queries.size(); i++) {
            result[i] = queryResult[queries[i]];
        }

        return result;
    }
};