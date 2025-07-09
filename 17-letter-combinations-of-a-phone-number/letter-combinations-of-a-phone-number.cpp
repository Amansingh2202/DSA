class Solution {
public:
    void create(int curr_index, string digits, vector<string>& ans, string& temp, unordered_map<char, string>& map) {
        if (curr_index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        char index = digits[curr_index];
        string current_string = map[index];

        for (int i = 0; i < current_string.size(); i++) {
            temp.push_back(current_string[i]);
            create(curr_index + 1, digits, ans, temp, map);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> map;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";

        vector<string> ans;
        string temp;

        create(0, digits, ans, temp, map);
        return ans;
    }
};
