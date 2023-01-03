class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 1) return strs[0];
        for (int i=0; i<=200; i++) {
            if (i < strs[0].length()) {
                char ch = strs[0][i];
                for (int j=1; j<n; j++) {
                    if (i >= strs[j].length() || strs[j][i] != ch) return strs[j].substr(0, i);
                }
            } else return strs[0].substr(0, i);
        }
        return "";
    }
};
