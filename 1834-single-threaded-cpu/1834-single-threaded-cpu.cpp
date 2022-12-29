class Solution {
public:
    typedef pair<int, int> T;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<T, vector<T>, greater<>> pq;
        long n = tasks.size(), time = 0, i = 0;
        for (int i = 0; i < n; i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        vector<int> ans;
        while (i < n || pq.size() > 0) {
            if (pq.empty()) time = max(time, (long)tasks[i][0]);
            while (i < n && time >= tasks[i][0]) {
                pq.emplace(tasks[i][1], tasks[i][2]);
                i++;
            }
            auto [pro, index] = pq.top();
            pq.pop();
            time += pro;
            ans.push_back(index);
        }
        return ans;
    }
};
