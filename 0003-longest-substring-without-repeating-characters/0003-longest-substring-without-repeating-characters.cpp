class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        map<char, int> m;
        int n = s.length();
        for (int i=0, j=0; i<n; i++) {
            if (m[s[i]] > 0) {
                j = max(j, m[s[i]]);
            }
            m[s[i]] = i+1;
            res = max(res, i-j+1);
        }
        return res;
    }
};
