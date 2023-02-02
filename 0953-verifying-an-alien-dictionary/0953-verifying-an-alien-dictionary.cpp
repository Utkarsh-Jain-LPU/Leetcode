class Solution {
public:
    bool isValid(string str1, string str2, map<char, int>& mp) {
        int m = str1.length();
        int n = str2.length();
        int i = 0;
        int c = min(m, n);
        while (i < c) {
            if (mp[str1[i]] < mp[str2[i]]) return true;
            if (mp[str1[i]] > mp[str2[i]]) return false;
            i++;
        }
        return m == c;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int n = order.length();
        map<char, int> mp;
        for (int i=0; i<n; i++) {
            mp[order[i]] = i;
        }
        int m = words.size();
        for (int i=1; i<m; i++) {
            if (!isValid(words[i-1], words[i], mp)) return false;
        }
        return true;
    }
};
