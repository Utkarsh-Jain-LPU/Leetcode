class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return n;
        int i = 0, j = 1;
        while (j < n) {
            if (nums[i] == nums[j]) j++;
            else {
                nums[i+1] = nums[j];
                i++, j++;
            }
        }
        return i+1;
    }
};
