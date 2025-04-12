class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        

        int n=nums.size();
    vector<int>ans(n,1);
  
     int suffix_product=1;

    

     for(int i=0;i<nums.size();i++)
     {

       
     ans[i]=nums[i]*suffix_product;

     suffix_product=ans[i];

     }

     int prefix_product=1;

     for(int i=nums.size()-1;i>=0;i--)
     {

       if(i==0)
       {

        ans[i]=prefix_product;
       }
       else{
                   ans[i]=ans[i-1]*prefix_product;
                   prefix_product*=nums[i];
       }
        
     }


     
  return ans;

    }
};