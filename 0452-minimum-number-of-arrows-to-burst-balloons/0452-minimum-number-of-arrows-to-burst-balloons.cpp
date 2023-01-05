class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) {
        return v1[1] != v2[1] ? v1[1] < v2[1] : v1[0] < v2[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        int count = 1;
        int curr = points[0][1];
        for (int i=1; i<points.size(); i++) {
            if (curr >= points[i][0]) {
                continue;
            }
            curr = points[i][1];
            count++;
        }
        return count;
    }
};
