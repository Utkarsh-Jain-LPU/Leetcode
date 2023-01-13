class Solution {
public:
    int calculate(vector<vector<int>>& adj, string& s, int node, int parent, int& res) {
        if (adj[node].size() == 0) return s[node] == s[parent] ? 0 : 1;
        int max1 = 0, max2 = 0;
        for (int child : adj[node]) {
            int len = calculate(adj, s, child, node, res);
            if (len > max1) max2 = max1, max1 = len;
            else if (len > max2) max2 = len;
        }
        res = max(res, max1 + max2 + 1);
        if (parent == -1) return max1 + max2 + 1;
        return s[node] == s[parent] ? 0 : max1 + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size(), res = 1;
        if (n == 1) return 1;
        vector<vector<int>> adj(n, vector<int>());
        for (int i=1; i<n; i++) adj[parent[i]].push_back(i);
        calculate(adj, s, 0, -1, res);
        return res;
    }
};
