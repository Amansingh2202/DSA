class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
         int r = mat.size();
      int c = mat[0].size();
      vector<int>ans;
        
        
	int top = 0, left = 0, bottom = r- 1, right = c - 1;

	while(top <= bottom && left <= right)
	{
		for(int i = left; i <= right; i++)
			{
                            ans.push_back(mat[top][i]);
                     }

		top++;

                for (int i = top; i <= bottom; i++) {
                            ans.push_back(mat[i][right]);
                }
                right--;

		if(top <= bottom){
		for(int i = right; i >= left; i--)
			ans.push_back(mat[bottom][i]);

		bottom--;
		}

		if(left <= right){
		for(int i = bottom; i >= top; i--)
			 ans.push_back(mat[i][left]);

		left++;
		}			
	}
       return ans;
    }
};