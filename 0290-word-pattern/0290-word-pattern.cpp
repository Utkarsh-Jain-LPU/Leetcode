class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int m = pattern.length();
        int n = s.length();
        int i = 0, j = 0, k = 0;
        map<char, string> mp1;
        map<string, char> mp2;
        while (j < n && k < m) {
            if (s[j] == ' ') {
                string str = s.substr(i, j-i);
                if (mp1[pattern[k]] == "" && mp2[str] == NULL) {
                    mp1[pattern[k]] = str;
                    mp2[str] = pattern[k];
                } else if (mp1[pattern[k]] != str || mp2[str] != pattern[k]) return false;
                k++;
                i = j+1;
            }
            j++;
        }
        if (k == m) return false;
        string str = s.substr(i, j-i);
        if (mp1[pattern[k]] == "" && mp2[str] == NULL && k+1 == m) return true;
        if (mp1[pattern[k]] != str || mp2[str] != pattern[k]) return false;
        return true;
    }
};
