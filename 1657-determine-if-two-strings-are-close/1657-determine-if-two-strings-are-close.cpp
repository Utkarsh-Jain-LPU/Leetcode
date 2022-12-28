class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;
        map<char, int> mp1, mp2;
        for (int i=0; i<word1.length(); i++) {
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }
        for (auto it=mp1.begin(); it!=mp1.end(); it++) {
            if (mp2[it->first] == 0) return false;
        }
        for (auto it=mp2.begin(); it!=mp2.end(); it++) {
            if (mp1[it->first] == 0) return false;
        }
        map<int, int> mp;
        for (auto it=mp1.begin(); it!=mp1.end(); it++) mp[it->second]++;
        for (auto it=mp2.begin(); it!=mp2.end(); it++) mp[it->second]--;
        for (auto it=mp.begin(); it!=mp.end(); it++) {
            if (it->second != 0) return false;
        }
        return true;
    }
};
