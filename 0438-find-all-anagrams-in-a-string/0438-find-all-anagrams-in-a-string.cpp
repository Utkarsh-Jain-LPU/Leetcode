class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<int> res;
        if (m < n) return res;
        vector<int> p_list(30, 0);
        vector<int> window(30, 0);
        for (int i=0; i<n; i++) {
            p_list[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        if (p_list == window) res.push_back(0);
        for (int i=n; i<m; i++) {
            window[s[i-n]-'a']--;
            window[s[i]-'a']++;
            if (p_list == window) res.push_back(i-n+1);
        }
        return res;
    }
};
