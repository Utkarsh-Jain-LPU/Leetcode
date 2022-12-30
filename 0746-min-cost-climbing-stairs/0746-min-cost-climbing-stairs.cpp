class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> v(n);
        v[0] = cost[0];
        v[1] = cost[1];
        for (int i=2; i<n; i++) {
            v[i] = min(cost[i]+v[i-1], cost[i]+v[i-2]);
        }
        return min(v[n-1], v[n-2]);
    }
};
