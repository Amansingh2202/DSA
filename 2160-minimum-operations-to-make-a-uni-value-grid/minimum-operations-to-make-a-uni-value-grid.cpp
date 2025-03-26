class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
         vector<int>flatter;

         for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                flatter.push_back(grid[row][col]);
            }
        }

         sort(flatter.begin(),flatter.end());

         int n=flatter.size();

         int number=flatter[n/2];

         
         int result=0;
      
         for(int i=0;i<n;i++)
         {

            if( (abs(number-flatter[i]))%x !=0)return -1;

            else{

                  result +=abs((number-flatter[i])/x);
            }
         }
        
       return result;
    }
};