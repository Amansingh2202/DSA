class Solution {
public:
      bool helper(string s,int start,vector<string>wordDict,unordered_set<string>holder)
      {
        if(start==s.length())return true;
        for(int index=start ;index<s.length();index++)
        {
            string word=s.substr(start,index-start+1);
            if(holder.find(word)!=holder.end()&& helper(s,index+1,wordDict,holder))
            {
                return true;
            }
        }
        return false;
      }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true; 
    for (int i = 1; i <= n; i++) {
        for (string word : wordDict) {
            int len = word.length();
            if (i >= len && s.substr(i - len, len) == word) {
                dp[i] = dp[i] || dp[i - len];
            }
        }
    }

    return dp[n];
    }
};