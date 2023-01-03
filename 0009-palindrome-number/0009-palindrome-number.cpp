class Solution {
public:
    string reverse(string str) {
        int n = str.length();
        int i = 0, j = n-1;
        while (i < j) {
            swap(str[i++], str[j--]);
        }
        return str;
    }
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string str = to_string(x);
        return str == reverse(str);
    }
};
