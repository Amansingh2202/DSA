class Solution {
public:
    
    void powerset(int index,vector<int>nums,vector<int> &dummy , vector<vector<int >>&ans,int n){
        if(index==n)
        {
            ans.push_back(dummy);
            return ;
        }
        
    
    dummy.push_back(nums[index]);
    powerset(index+1,nums,dummy,ans,n);
    dummy.pop_back();
    powerset(index+1,nums,dummy,ans,n);

return ;
    }
    



    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
       vector<vector<int>>ans;
        vector<int>dummy;
        powerset(0,nums,dummy,ans,n);
        return ans;
    }

    
};