class Solution {
public:
    bool find(string& haystack, string& needle, int i, int n) {
        for (int k=0; k<n; k++) {
            if (haystack[k+i] != needle[k]) return false;
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        if (m < n) return -1;
        for (int i=0; i<=m-n; i++) {
            if (haystack[i] == needle[0]) {
                if (find(haystack, needle, i, n)) return i;
            }
        }
        return -1;
    }
};
