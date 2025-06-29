
class Solution {
public:
    void generate(int index, vector<vector<int>>& ans, vector<int>& pick, vector<int>& temp, vector<int>& nums, int n) {
        if (index == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (pick[i] == 0) {
                temp.push_back(nums[i]);
                pick[i] = 1;
                generate(index + 1, ans, pick, temp, nums, n);
                pick[i] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> pick(n, 0);
        vector<vector<int>> ans;
        vector<int> temp;
        generate(0, ans, pick, temp, nums, n);
        return ans;
    }
};
