class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = -1;
        int insertLoc = -1;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (nums[i] == target) {
                index = i;
                break;
            } else {
                if (nums[i] > target) {
                    insertLoc = i;
                    break;
                }
            }
        }
        if (insertLoc == -1) insertLoc = n;
        if (index != -1) return index;
        return insertLoc;
    }
};
