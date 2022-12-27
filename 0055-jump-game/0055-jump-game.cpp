class Solution {
public:
    bool canJump(vector<int>& nums) {
        int j = nums.size()-1;
        while (j > 0) {
            int x = j;
            for (int i=0; i<j; i++) {
                if (i+nums[i] >= j) {
                    j = i;
                    break;
                }
            }
            if (x == j) return false;
        }
        return true;
    }
};
