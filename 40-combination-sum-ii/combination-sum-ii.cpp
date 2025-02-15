class Solution {
public:
    void get_ans(int index,int target,vector<int>& candidates,int n,vector<vector<int>>& ans,vector<int>& temp)
    {   
        
         if (target == 0) {  // Found a valid combination
            ans.push_back(temp);
            return;
        }
        if (index == n || target < 0) return;  // Base case

        // Include the current element
        temp.push_back(candidates[index]);
        get_ans(index + 1, target - candidates[index], candidates, n, ans, temp);
        temp.pop_back();

        // Skip all duplicate elements
        while (index + 1 < n && candidates[index] == candidates[index + 1]) {
            index++;
        }

        // Move to the next unique element
        get_ans(index + 1, target, candidates, n, ans, temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        int current=0;
        get_ans(0,target,candidates,n,ans,temp);
        return ans;

    }
};