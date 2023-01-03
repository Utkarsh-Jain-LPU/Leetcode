class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0;
        int curr = nums[0];
        int count = 1;
        int n = nums.size();
        for (int i=1; i<n; i++) {
            if (nums[i] == curr) {
                count++;
                if (count <= 2) res++;
            } else {
                curr = nums[i];
                count = 1;
                res++;
            }
            swap(nums[i], nums[res]);
        }
        return res+1;
    }
};
