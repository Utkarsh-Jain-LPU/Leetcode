class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int t_gas = 0, t_cost = 0;
        for (int i=0; i<n; i++) {
            t_gas += gas[i];
            t_cost += cost[i];
        }
        if (t_gas < t_cost) return -1;
        int start = 0, curr_gas = 0;
        for (int i=0; i<n; i++) {
            if (curr_gas < 0) {
                start = i;
                curr_gas = 0;
            }
            curr_gas = curr_gas - cost[i] + gas[i];
        }
        return start;
    }
};
