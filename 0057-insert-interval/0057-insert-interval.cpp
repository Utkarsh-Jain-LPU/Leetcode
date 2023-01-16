class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (n > 0 && newInterval[1] < intervals[0][0]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0]) i++;
        if (i == n) {
            intervals.push_back(newInterval);
            return intervals;
        }
        if (intervals[i][0] > newInterval[1]) {
            intervals.insert(intervals.begin()+i, newInterval);
            return intervals;
        }
        int start = min(newInterval[0], intervals[i][0]);
        int end = max(newInterval[1], intervals[i][1]);
        intervals.erase(intervals.begin()+i);
        n--;
        while (i < n && end >= intervals[i][0]) {
            end = max(end, intervals[i][1]);
            intervals.erase(intervals.begin()+i);
            n--;
        }
        vector<int> v{start, end};
        intervals.insert(intervals.begin()+i, v);
        return intervals;
    }
};
