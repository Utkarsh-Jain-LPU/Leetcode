class Solution {
public:
    char repeatedCharacter(string s) {
        map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
            if (mp[ch] > 1) return ch;
        }
        return ' ';
    }
};
