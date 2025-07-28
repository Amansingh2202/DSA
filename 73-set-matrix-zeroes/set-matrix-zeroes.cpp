class Solution {
public:
void make(vector<vector<int>>& matrix,int row,int col,int r,int c)
{
    for(int i=0;i<row;i++)
    {
        matrix[i][c]=0;
    }
    for(int j=0;j<col;j++)
    {
        matrix[r][j]=0;
    }
}
    void setZeroes(vector<vector<int>>& matrix) {
           
    queue<pair<int,int>>Q;    
         int m=matrix.size();
         int n=matrix[0].size();
         for(int i=0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                   Q.push({i,j});
                }
            }
         }
       while(!Q.empty()){
        int i=Q.front().first;
        int j=Q.front().second;
        Q.pop();
        make(matrix,m,n,i,j);
       }
    }
};