class Solution {
public:
 void backtrack(int index, const string &digits, vector<string> &phoneMap, string &path, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }

        string letters = phoneMap[digits[index] - '0'];
        for (char ch : letters) {
            path.push_back(ch);
            backtrack(index + 1, digits, phoneMap, path, result);
            path.pop_back();  // backtrack
        }
    }


    vector<string> letterCombinations(string digits) {
         if (digits.empty()) return {};
        
        vector<string> phoneMap = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string path;
        backtrack(0, digits, phoneMap, path, result);
        return result;

    }
};