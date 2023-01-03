class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s == "") return 0;
        int lastIndex = s.length();
        for (int i=s.length()-1; i>=0; i--) {
            if (s[i] != ' ') {
                lastIndex = i;
                break;
            }
        }
        int startIndex = 0;
        for (int i=lastIndex; i>=0; i--) {
            if (s[i] == ' ') {
                startIndex = i+1;
                break;
            }
        }
        return lastIndex-startIndex+1;
    }
};
