class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = 0;
        int temp1 = 1, temp2 = 1;
        int n = nums.size();
        if (n == 1) return nums[0];
        for (int i=0, j=n-1; i<n; i++, j--) {
            if (nums[i] == 0) temp1 = 1;
            else {
                temp1 *= nums[i];
                res = max(res, temp1);
            }
            if (nums[j] == 0) temp2 = 1;
            else {
                temp2 *= nums[j];
                res = max(res, temp2);
            }
        }
        return res;
    }
};
