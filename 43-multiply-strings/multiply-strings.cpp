class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size(), m = num2.size();
        vector<int> ans(n + m, 0);


        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = ans[i + j + 1] + mul;
                ans[i + j + 1] = sum % 10;
                ans[i + j] += sum / 10;
            }
        }

       
        string result;
        bool leadingZero = true;
        for (int digit : ans) {
            if (digit == 0 && leadingZero) continue;
            leadingZero = false;
            result += (digit + '0');
        }

        return result.empty() ? "0" : result;
    }
};
