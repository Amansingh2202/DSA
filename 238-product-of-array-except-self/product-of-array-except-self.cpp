class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);  

        int prefix_product = 1;

  
        for (int i = 0; i < n; i++) {
            ans[i] = prefix_product;
            prefix_product *= nums[i];
        }

        int suffix_product = 1;

  
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix_product;
            suffix_product *= nums[i];
        }

        return ans;
    }
};
