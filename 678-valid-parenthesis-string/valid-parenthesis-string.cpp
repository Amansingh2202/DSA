class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, asterisk = 0;

    
        for (char c : s) {
            if (c == '(') open++;
            else if (c == '*') asterisk++;
            else { 
                if (open > 0) open--;
                else if (asterisk > 0) asterisk--;
                else return false;
            }
        }

      
        open = 0, asterisk = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') open++;
            else if (s[i] == '*') asterisk++;
            else { 
                if (open > 0) open--;
                else if (asterisk > 0) asterisk--;
                else return false;
            }
        }

        return true;
    }
};
