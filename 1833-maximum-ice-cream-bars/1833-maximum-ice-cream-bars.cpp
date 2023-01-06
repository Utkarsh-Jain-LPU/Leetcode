class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int n = costs.size();
        int count = 0, i = 0;
        while (i < n && coins >= costs[i]) {
            count++;
            coins -= costs[i];
            i++;
        }
        return count;
    }
};
