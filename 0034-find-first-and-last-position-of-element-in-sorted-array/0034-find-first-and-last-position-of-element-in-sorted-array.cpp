class Solution {
public:
    int startIndex = -1;
    int lastIndex = -1;
    void find(vector<int>& nums, int i, int j, int target) {
        if (i > j) return;
        int mid = (i+j)/2;
        if (nums[mid] == target) {
            startIndex = (startIndex == -1) ? mid : (startIndex <= mid) ? startIndex : mid;
            lastIndex = (lastIndex == -1) ? mid : (lastIndex >= mid) ? lastIndex : mid;
            find(nums, i, mid-1, target);
            find(nums, mid+1, j, target);
        } else if (nums[mid] > target) {
            find(nums, i, mid-1, target);
        } else {
            find(nums, mid+1, j, target);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        find(nums, 0, nums.size()-1, target);
        vector<int> res;
        res.push_back(startIndex);
        res.push_back(lastIndex);
        return res;
    }
};
