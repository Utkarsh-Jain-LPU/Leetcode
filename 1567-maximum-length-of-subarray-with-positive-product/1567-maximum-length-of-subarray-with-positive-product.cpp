class Solution {
public:
    int getLength(vector<int>& nums, int start, int end) {
        if (start > end) return 0;
        int negCount = 0, firstNeg = -1;
        for (int i=start; i<=end; i++) {
            if (nums[i] < 0) {
                negCount++;
                if (firstNeg == -1) firstNeg = i;
            }
        }
        if (negCount%2 == 0) return end-start+1;
        int lastNeg = -1;
        for (int i=end; i>=start; i--) {
            if (nums[i] < 0 && lastNeg == -1) {
                lastNeg = i;
                break;
            }
        }
        return max(lastNeg-start, end-firstNeg);
    }
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int startZero = -1, res = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] == 0) {
                res = max(res, getLength(nums, startZero+1, i-1));
                startZero = i;
            }
        }
        res = max(res, getLength(nums, startZero+1, n-1));
        return res;
    }
};
