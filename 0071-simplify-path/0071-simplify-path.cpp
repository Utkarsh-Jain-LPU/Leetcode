class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        stack<char> stk;
        stk.push('/');
        int i = 1;
        while (i < n) {
            if (path[i] == '/') {
                if (stk.top() != '/') {
                    stk.push(path[i]);
                }
                i++;
                continue;
            }
            if (path[i] == '.') {
                if (stk.top() != '/') {
                    stk.push(path[i]);
                    i++;
                    continue;
                }
                if (i+1 < n && path[i+1] != '/') {
                    if (path[i+1] != '.') {
                        stk.push('.');
                        stk.push(path[i+1]);
                        i += 2;
                        continue;
                    }
                    if (i+2 < n && path[i+2] != '/') {
                        stk.push('.');
                        stk.push('.');
                        stk.push(path[i+2]);
                        i += 3;
                        continue;
                    }
                    if (stk.size() != 1) {
                        stk.pop();
                        while (!stk.empty() && stk.top() != '/') stk.pop();
                        if (stk.size() != 1) stk.pop();
                    }
                    i += 2;
                    continue;
                }
                i++;
                continue;
            }
            stk.push(path[i++]);
        }
        if (stk.size() == 1) {
            string s(1, stk.top());
            return s;
        }
        if (stk.top() == '/') stk.pop();
        string str = "";
        while (!stk.empty()) {
            string s(1, stk.top());
            str = s + str;
            stk.pop();
        }
        return str;
    }
};
