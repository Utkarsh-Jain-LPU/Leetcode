class Solution {
public:
    bool halvesAreAlike(string s) {
        int len = s.length(), c1 = 0, c2 = 0;
        string data = "aAeEiIoOuU";
        for (int i=0; i<len/2; i++) {
            if (data.find(s[i]) != string::npos) c1++;
        }
        for (int i=len/2; i<len; i++) {
            if (data.find(s[i]) != string::npos) c2++;
        }
        return c1==c2;
    }
};
