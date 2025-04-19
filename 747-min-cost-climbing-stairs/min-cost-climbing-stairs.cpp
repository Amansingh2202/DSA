class Solution {
public:
 int helper(int n,vector<int> cost,vector<int>&dp)
  {

       if(n==1)return cost[1];
       if(n==0) return cost[0];

       int left;
       int right;

        if(dp[n]!=-1)return dp[n];
       if(n==cost.size())
       {

         left=helper(n-1,cost,dp);
         right=helper(n-2,cost,dp);

       }
       else{
         

          left=helper(n-1,cost,dp)+cost[n];
          right=helper(n-2,cost,dp)+cost[n];


       }
       return dp[n]=min(left,right);




  }
    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size();
        vector<int>dp(n+1,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];

        return dp[n]=helper(n,cost,dp);
    }
};