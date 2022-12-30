class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0;
        int j = nums.size()-1;
        while (j > 0) {
            for (int i=0; i<j; i++) {
                if ((i+nums[i]) >= j) {
                    j = i;
                    steps++;
                    break;
                }
            }
        }
        return steps;
    }
};
