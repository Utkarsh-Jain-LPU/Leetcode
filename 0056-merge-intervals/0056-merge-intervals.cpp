class Solution {
public:
    bool static compare(vector<int> v1, vector<int> v2) {
        if (v1[0] != v2[0]) return v1[0] < v2[0];
        return v1[1] < v2[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), compare);
        int term1 = intervals[0][0], term2 = intervals[0][1];
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i][0] <= term2) {
                term2 = max(term2, intervals[i][1]);
                continue;
            }
            vector<int> v;
            v.push_back(term1);
            v.push_back(term2);
            res.push_back(v);
            term1 = intervals[i][0];
            term2 = intervals[i][1];
        }
        vector<int> v;
        v.push_back(term1);
        v.push_back(term2);
        res.push_back(v);
        return res;
    }
};
