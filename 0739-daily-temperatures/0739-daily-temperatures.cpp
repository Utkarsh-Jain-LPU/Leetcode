class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> vec(n);
        stack<pair<int, int>> stk;
        stk.push({temperatures[0], 0});
        for (int i=1; i<n; i++) {
            if (stk.empty()) {
                stk.push({temperatures[i], i});
                continue;
            }
            while (!stk.empty() && stk.top().first < temperatures[i]) {
                pair<int, int> &p = stk.top();
                stk.pop();
                vec[p.second] = i-(p.second);
            }
            stk.push({temperatures[i], i});
        }
        while (!stk.empty()) {
            pair<int, int> &p = stk.top();
            stk.pop();
            vec[p.second] = 0;
        }
        return vec;
    }
};
