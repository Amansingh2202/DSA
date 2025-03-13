class Solution {
    
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
         int n = nums.size();
    std::vector<int> line(n + 1, 0);
    int decrement = 0;
    int k = 0;

    for (int i = 0; i < n; ++i) {
      while (decrement + line[i] < nums[i]) {
        if (k == queries.size())
          return -1;
        int l = queries[k][0];
        int r = queries[k][1];
        int val = queries[k][2];
        ++k;
        if (r < i)
          continue;
        line[std::max(l, i)] += val;
        line[r + 1] -= val;
      }
      decrement += line[i];
    }

    return k;
    }
};