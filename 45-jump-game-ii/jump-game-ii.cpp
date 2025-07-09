class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> steps(nums.size(), INT_MAX);
        steps[0] = 0;

        for (int i = 0; i < nums.size(); i++) {
            int step = steps[i];
            for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
                if (step + 1 < steps[i + j]) {
                    steps[i + j] = step + 1;
                }
            }
        }

        return steps.back();
    }
};
