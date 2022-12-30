class Solution {
public:
    int find(string s, int i, int n, vector<int>& vec) {
        if (i == n) return 1;
        if (vec[i] != -1) return vec[i];
        int n1 = s[i]-'0';
        if (n1 == 0) {
            vec[i] = 0;
            return 0;
        }
        int res = find(s, i+1, n, vec);
        if (i+1 < n) {
            int n2 = s[i+1]-'0';
            int num = (n1*10)+n2;
            if (num <= 26) {
                res += find(s, i+2, n, vec);
            }
        }
        vec[i] = res;
        return res;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> vec(n+1, -1);
        return find(s, 0, n, vec);
    }
};
