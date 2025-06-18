class Solution {
public:
int  bfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid)
   {            
                   vis[row][col]=1;
              queue<pair<int,int>>Q;
              int n=grid.size();
              int m=grid[0].size();
              Q.push({row,col});

              int cnt=1;

              while(!Q.empty())
              {
                       
                   int nrow=Q.front().first;
                   int ncol=Q.front().second;
                   Q.pop();

                   int drow[] = {-1, 0, 1, 0};
                   int dcol[] = {0, 1, 0, -1};

                   for(int i=0; i<4; i++)
                     {
                           int delrow = nrow + drow[i];
                           int delcol = ncol + dcol[i];

    if(delrow>=0 && delrow<n && delcol>=0 && delcol<m && 
       !vis[delrow][delcol] && grid[delrow][delcol]==1)
    {
        vis[delrow][delcol] = 1;
        Q.push({delrow, delcol});
        cnt++;
    }
}

              }
 return cnt;
              }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=0;
             int n=grid.size();
             int m=grid[0].size();
             vector<vector<int>>vis(n,vector<int>(m,0));

             for(int i=0;i<n;i++)
             {
                for(int j=0;j<m;j++)
                {
                    if(!vis[i][j] &&  grid[i][j]==1){
                         
                         
                      count =max(count,bfs(i,j,vis,grid));
                    }
                }
    }
    return count;
    }
};