class Solution {
public:
     void getans(int  index,int n,vector<int>&temp,vector<int>nums,vector<vector<int>>&ans)
     {
        if(index==n)
        {
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[index]);
        getans(index+1,n,temp,nums,ans);
        temp.pop_back();
        while(index+1<n && nums[index]==nums[index+1])
        {
            index++;
        }
           getans(index+1,n,temp,nums,ans);
     } 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        getans(0,n,temp,nums,ans);
        return ans;
    }
};