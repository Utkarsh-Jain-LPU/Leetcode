class Solution {
public:
    void dfs(int i, int dist, vector<int>& edges, vector<int>& m) {
        while (i != -1 && m[i] == -1) {
            m[i] = dist++;
            i = edges[i];
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        int res = -1, min_dist = INT_MAX;
        vector<int> m1(n, -1), m2(n, -1);
        dfs(node1, 0, edges, m1);
        dfs(node2, 0, edges, m2);
        for (int i=0; i<n; i++) {
            if (min(m1[i], m2[i]) >= 0 && max(m1[i], m2[i]) < min_dist) {
                min_dist = max(m1[i], m2[i]);
                res = i;
            }
        }
        return res;
    }
};
