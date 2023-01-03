class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while (i < j) {
            int mid = (i+j)/2;
            if (nums[mid] > nums[j]) i = mid+1;
            else j = mid;
        }
        int pivot = i;
        i = 0, j = nums.size()-1;
        while (i <= j) {
            int mid = (i+j)/2;
            int realMid = (mid+pivot)%nums.size();
            if (nums[realMid] == target) return realMid;
            else if (nums[realMid] < target) i = mid+1;
            else j = mid-1;
        }
        return -1;
    }
};
