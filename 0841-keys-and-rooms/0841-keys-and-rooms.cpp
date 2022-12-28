class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> que;
        visited[0] = true;
        for (int key : rooms[0]) {
            que.push(key);
            visited[key] = true;
        }
        while (!que.empty()) {
            int key = que.front();
            que.pop();
            for (int newKey : rooms[key]) {
                if (!visited[newKey]) {
                    que.push(newKey);
                    visited[newKey] = true;
                }
            }
        }
        for (bool isVisited : visited) {
            if (!isVisited) return false;
        }
        return true;
    }
};
