class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk;
        for (int i=0; i<tokens.size(); i++) {
            string str = tokens[i];
            if (str != "+" && str != "-" && str != "*" && str != "/") {
                stk.push(stoi(str));
                continue;
            }
            long long num1 = stk.top();
            stk.pop();
            long long num2 = stk.top();
            stk.pop();            
            if (str == "+") stk.push(num1+num2);
            else if (str == "-") stk.push(num2-num1);
            else if (str == "*") stk.push(num1*num2);
            else stk.push(num2/num1);
        }
        return (int)stk.top();
    }
};
