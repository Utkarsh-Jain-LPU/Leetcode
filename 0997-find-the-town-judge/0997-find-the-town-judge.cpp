class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> trust_on(n+1), trusted(n+1);
        for (vector<int>& v : trust) {
            trust_on[v[0]].push_back(v[1]);
            trusted[v[1]].push_back(v[0]);
        }
        for (int i=1; i<=n; i++) {
            if (trust_on[i].size() > 0) continue;
            if (trusted[i].size() == n-1) return i;
        }
        return -1;
    }
};
