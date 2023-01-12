class Solution {
public:
    map<char, int> calculate(vector<vector<int>>& adj, vector<bool>& visited, int node, string& labels, int n, vector<int>& res) {
        visited[node] = true;
        map<char, int> mp;
        for (int x : adj[node]) {
            if (!visited[x]) {
                map<char, int> m = calculate(adj, visited, x, labels, n, res);
                for (auto [key, value] : m) mp[key] += value;
            }
        }
        res[node] = mp[labels[node]] + 1;
        mp[labels[node]]++;
        return mp;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n, vector<int>());
        for (vector<int>& v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n, false);
        vector<int> res(n, 0);
        calculate(adj, visited, 0, labels, n, res);
        return res;
    }
};
