class Solution {
public:
    int maxArea(vector<int>& height) {
        
     
       int breath=height.size()-1;

       int ans=INT_MIN;

       int left=0;
       int right=breath;
       while(left<right)
       {
          int length=min(height[right],height[left]);

          int area=breath*length;

          ans=max(ans,area);

          if(height[right]>=height[left])
          {
            left++;
          }
          else{
            right--;
          }
          breath--;




       }
       return ans;

    }
};