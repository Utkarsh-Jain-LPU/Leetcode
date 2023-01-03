class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                v.push_back(s[i]);
            } else {
                if (s[i] == ')') {
                    if (v.size() != 0 && v[v.size()-1] == '(') {
                        v.pop_back();
                    } else {
                        return false;
                    }
                } else if (s[i] == '}') {
                    if (v.size() != 0 && v[v.size()-1] == '{') {
                        v.pop_back();
                    } else {
                        return false;
                    }
                } else {
                    if (v.size() != 0 && v[v.size()-1] == '[') {
                        v.pop_back();
                    } else {
                        return false;
                    }
                }
            }
        }
        return v.size()==0;
    }
};
