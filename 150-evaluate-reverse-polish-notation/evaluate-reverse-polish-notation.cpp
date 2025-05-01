#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (auto ch : tokens) {
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                int val2 = s.top(); s.pop();
                int val1 = s.top(); s.pop();
                int temp;

                if (ch == "+") temp = val1 + val2;
                else if (ch == "-") temp = val1 - val2;
                else if (ch == "*") temp = val1 * val2;
                else if (ch == "/") temp = val1 / val2;

                s.push(temp);
            } else {
                s.push(stoi(ch));
            }
        }

        return s.top();
    }
};
