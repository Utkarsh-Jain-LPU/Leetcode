class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        if (n == 2) return (nums[0] == nums[1]) ? 1 : 2;
        vector<int> vec(n);
        vec[0] = 0;
        for (int i=1; i<n; i++) {
            if (nums[i] > nums[i-1]) vec[i] = 1;
            else if (nums[i] < nums[i-1]) vec[i] = -1;
            else vec[i] = vec[i-1];
        }
        int curr = vec[1];
        int count = (vec[0] == vec[1]) ? 1 : 0;
        for (int i=2; i<n; i++) {
            if (vec[i] != curr) {
                curr = vec[i];
                continue;
            }
            count++;
        }
        return n-count;
    }
};
