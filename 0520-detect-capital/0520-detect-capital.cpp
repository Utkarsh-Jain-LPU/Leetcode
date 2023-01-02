class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        if (n == 1) return true;
        bool isCap = (word[1] >= 'a' && word[1] <= 'z') ? false : true;
        char s = isCap ? 'A' : 'a';
        char e = isCap ? 'Z' : 'z';
        for (int i=2; i<n; i++) {
            if (word[i] < s || word[i] > e) return false;
        }
        return isCap ? ((word[0] >= 'A' && word[0] <= 'Z') ? true : false) : true;
    }
};
