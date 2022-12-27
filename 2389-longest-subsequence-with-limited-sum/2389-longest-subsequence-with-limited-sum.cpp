class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> temp(n);
        temp[0] = nums[0];
        for (int i=1; i<n; i++) temp[i] = temp[i-1]+nums[i];
        vector<int> res(queries.size());
        for (int i=0; i<queries.size(); i++) {
            bool found = false;
            for (int j=0; j<n; j++) {
                if (temp[j] == queries[i]) {
                    res[i] = j+1;
                    found = true;
                    break;
                }
                if (temp[j] > queries[i]) {
                    res[i] = j;
                    found = true;
                    break;
                }
            }
            if (!found) res[i] = n;
        }
        return res;
    }
};
