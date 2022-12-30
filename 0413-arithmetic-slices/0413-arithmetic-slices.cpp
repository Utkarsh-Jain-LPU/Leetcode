class Solution {
public:
    bool isAP(vector<int>& nums, int i, int j) {
        int diff = nums[i+1] - nums[i];
        for (int k=i+2; k<=j; k++) {
            if (nums[k] - nums[k-1] != diff) return false;
        }
        return true;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int count = 0;
        while (j < n) {
            if (j-i+1 < 3) {
                j++;
                continue;
            }
            if (isAP(nums, i, j)) {
                count += (j-i+1) - 3 + 1;
                j++;
                continue;
            }
            i++;
        }
        return count;
    }
};
