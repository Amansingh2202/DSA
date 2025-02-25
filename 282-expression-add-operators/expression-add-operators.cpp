#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        backtrack(result, num, target, "", 0, 0, 0);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& num, int target, string path, int index, long eval, long prevNum) {
        if (index == num.size()) {
            if (eval == target) result.push_back(path);
            return;
        }

        for (int i = index; i < num.size(); i++) {
            if (i > index && num[index] == '0') break; // Skip leading zeros

            string currStr = num.substr(index, i - index + 1);
            long currNum = stol(currStr);

            if (index == 0) {
                // First number, no operator needed
                backtrack(result, num, target, path + currStr, i + 1, currNum, currNum);
            } else {
                // Addition
                backtrack(result, num, target, path + "+" + currStr, i + 1, eval + currNum, currNum);

                // Subtraction
                backtrack(result, num, target, path + "-" + currStr, i + 1, eval - currNum, -currNum);

                // Multiplication
                backtrack(result, num, target, path + "*" + currStr, i + 1, eval - prevNum + (prevNum * currNum), prevNum * currNum);
            }
        }
    }
};
