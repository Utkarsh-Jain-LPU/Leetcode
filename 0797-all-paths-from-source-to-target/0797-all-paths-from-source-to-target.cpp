class Solution {
public:
    void calculate(vector<vector<int>>& adj, int node, vector<int> vec, vector<vector<int>>& res) {
        if (node == 0) {
            vec.insert(vec.begin(), node);
            res.push_back(vec);
            return;
        }
        vec.insert(vec.begin(), node);
        for (int k=0; k<adj[node].size(); k++) {
            calculate(adj, adj[node][k], vec, res);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n, vector<int>());
        for (int i=0; i<n; i++) {
            for (int j=0; j<graph[i].size(); j++) adj[graph[i][j]].push_back(i);
        }
        vector<vector<int>> res;
        calculate(adj, n-1, {}, res);
        return res;
    }
};
