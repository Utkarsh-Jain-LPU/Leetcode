class Solution {
public:
    void findCount(vector<vector<int>>& adj, vector<int>& visited, int root, vector<int>& count, int len, vector<int>& res) {
        visited[root] = 1;
        res[0] += len;
        for (int child : adj[root]) {
            if (visited[child]) continue;
            findCount(adj, visited, child, count, len+1, res);
            count[root] += count[child];
        }
    }
    void calculate(vector<vector<int>>& adj, vector<int>& visited, int root, int n, vector<int>& count, vector<int>& res) {
        visited[root] = 1;
        for (int child : adj[root]) {
            if (visited[child]) continue;
            res[child] = res[root]-count[child]+(n-count[child]);
            calculate(adj, visited, child, n, count, res);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for (vector<int> g : edges) {
            adj[g[0]].push_back(g[1]);
            adj[g[1]].push_back(g[0]);
        }
        vector<int> res(n, 0), count(n, 1), visited(n, 0);
        findCount(adj, visited, 0, count, 0, res);
        for (int i=0; i<n; i++) visited[i] = 0;
        calculate(adj, visited, 0, n, count, res);
        return res;
    }
};
