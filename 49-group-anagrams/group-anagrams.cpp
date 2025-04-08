class Solution {
public:

    // bool isAnagram(string s, string t) {
    
    //    if(s.size()!=t.size())return false;

    //    unordered_map<char,int>mps,mpt;
    //    for(int i=0;i<s.size();i++)
    //    {
    //       mps[s[i]]++;
    //       mpt[t[i]]++;
    //    }
    //    for(int i=0;i<s.size();i++)
    //    {
    //      if( mps[s[i]]!=mpt[s[i]])return  false; 


    //    }
    //    return true;

    // }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> res;
        for (const auto& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};