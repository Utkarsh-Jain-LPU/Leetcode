class Solution {
public:
    int calculate(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        } else if (nums.size() == 3) {
            return max(nums[0]+nums[2], nums[1]);
        }
        nums[2] += nums[0];
        for (int i=3; i<nums.size(); i++) {
            nums[i] = max(nums[i]+nums[i-2], nums[i]+nums[i-3]);
        }
        return max(nums[nums.size()-1], nums[nums.size()-2]);
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> vec = nums;
        vec.pop_back();
        nums.erase(nums.begin());
        return max(calculate(nums), calculate(vec));
    }
};
