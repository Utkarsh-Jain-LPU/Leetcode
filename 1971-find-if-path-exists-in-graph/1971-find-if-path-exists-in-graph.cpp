class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        map<int, vector<int>> mp;
        for (vector<int>& pair : edges) {
            mp[pair[0]].push_back(pair[1]);
            mp[pair[1]].push_back(pair[0]);
        }
        queue<int> q;
        q.push(source);
        vector<bool> visited(n, false);
        visited[source] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int dest : mp[node]) {
                if (dest == destination) return true;
                if (!visited[dest]) {
                    q.push(dest);
                    visited[dest] = true;
                }
            }
        }
        return false;
    }
};
