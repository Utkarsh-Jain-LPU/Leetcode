class Solution {
public:
    void dfs(int idx, int caller, vector<vector<int>> &adjList, vector<vector<int>> &outgoing, vector<bool> &visited, int &ans) {
        visited[idx] = true;
        if (caller != -1) {
            if (find(outgoing[idx].begin(), outgoing[idx].end(), caller) == outgoing[idx].end()) ans++;
        }
        for (auto i : adjList[idx]) {
            if (!visited[i]) {
                dfs(i, idx, adjList, outgoing, visited, ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        int ans = 0;
        vector<vector<int>> adjList(n);
        vector<vector<int>> outgoing(n);
        vector<bool> visited(n, false);       
        for (auto i : connections) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
            outgoing[i[0]].push_back(i[1]);
        }
        dfs(0, -1, adjList, outgoing, visited, ans);
        return ans;
    }
};
