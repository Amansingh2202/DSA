class Solution {
public:

    void func(int ind, vector<int>& v, int sum, int k, int n, vector<vector<int>>& ans, vector<int>& nums) {
        if (sum == 0 && v.size() == k) {
            ans.push_back(v);
            return;
        } 
        if (sum < 0 || ind == n || v.size() == k) {
            return;
        }
        v.push_back(nums[ind]);
        func(ind + 1, v, sum - nums[ind], k, n, ans, nums);
        v.pop_back();
        func(ind + 1, v, sum, k, n, ans, nums);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int sz = nums.size();
        vector<int> v;
        vector<vector<int>> ans;
        func(0, v, n, k, sz, ans, nums);
        return ans;
    }
};