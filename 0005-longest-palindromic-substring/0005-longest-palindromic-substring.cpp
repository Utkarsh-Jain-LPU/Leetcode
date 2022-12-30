class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<pair<int, int>> vec(n);
        for (int k=0; k<n; k++) {
            int i = k-1, j = k+1;
            while (i >= 0 && j < n && s[i] == s[j]) {
                i--;
                j++;
            }
            vec[k] = {i+1, j-1};
            if (k-1 >= 0 && s[k] == s[k-1]) {
                i = k-2;
                j = k+1;
                while (i >= 0 && j < n && s[i] == s[j]) {
                    i--;
                    j++;
                }
                if (j-i-1 > vec[k].second-vec[k].first+1) {
                    vec[k] = {i+1, j-1};
                }
            }
        }
        int max = 0;
        string str = "";
        for (auto [a, b] : vec) {
            if (b-a+1 > max) {
                max = b-a+1;
                str = s.substr(a, max);
            }
        }
        return str;
    }
};
