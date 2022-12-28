class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
        for (vector<int> group : dislikes) {
            adj[group[0]][group[1]] = 1;
            adj[group[1]][group[0]] = 1;
        }
        vector<int> color(n+1, 0);
        vector<bool> visited(n+1, false);
        for (int i=1; i<=n; i++) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while (!q.empty()) {
                    int p = q.front();
                    q.pop();
                    if (visited[p]) continue;
                    visited[p] = true;
                    for (int j=1; j<=n; j++) {
                        if (adj[p][j] == 1) {
                            if (color[j] == color[p]) return false;
                            color[j] = -color[p];
                            q.push(j);
                        }
                    }
                }
            }
        }
        return true;
    }
};
