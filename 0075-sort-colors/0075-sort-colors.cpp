class Solution {
public:
    int sort(vector<int>& nums, int left, int right, int val) {
        int i = left-1;
        int j = left;
        while (j <= right) {
            if (nums[j] == val) {
                i++;
                swap(nums[i], nums[j]);
            }
            j++;
        }
        return i+1;
    }
    void sortColors(vector<int>& nums) {
        int k = sort(nums, 0, nums.size()-1, 0);
        sort(nums, k, nums.size()-1, 1);
    }
};
