class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& ocean) {
        int n = heights.size();
        int m = heights[0].size();
        ocean[i][j] = true;

        for (int d = 0; d < 4; ++d) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
                !ocean[ni][nj] &&
                heights[ni][nj] >= heights[i][j]) {
                dfs(ni, nj, heights, ocean);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        vector<vector<int>> result;

        // DFS from Pacific border (top row & left column)
        for (int i = 0; i < n; ++i) {
            dfs(i, 0, heights, pacific);
            dfs(i, m - 1, heights, atlantic);
        }

        for (int j = 0; j < m; ++j) {
            dfs(0, j, heights, pacific);
            dfs(n - 1, j, heights, atlantic);
        }

        // Collect result: cells reachable from both oceans
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
