class Solution {
public:
    void powerset(int n,vector<int>nums,vector<int> &dummy , vector<vector<int >>&ans){
        if(n<0)
        {
            ans.push_back(dummy);
            return ;
        }
        
    
    dummy.push_back(nums[n]);
    powerset(n-1,nums,dummy,ans);
    dummy.pop_back();
    powerset(n-1,nums,dummy,ans);

return ;
    }
    



    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
       vector<vector<int>>ans;
        vector<int>dummy;
        powerset(n-1,nums,dummy,ans);
        return ans;
    }
};