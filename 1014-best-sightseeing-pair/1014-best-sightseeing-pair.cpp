class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int currMax = values[0];
        int res = -1;
        for (int i=1; i<values.size(); i++) {
            res = max(res, currMax+values[i]-i);
            currMax = max(currMax, values[i]+i);
        }
        return res;
    }
};
