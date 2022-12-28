class Solution {
public:
    int getVal(vector<long>& backward, vector<int>& nums, int i, int len) {
        return (i != len-1) ? (backward[i]-nums[i])/(len-i-1) : 0;
    }
    int minimumAverageDifference(vector<int>& nums) {
        int len = nums.size();
        vector<long> forward(len, 0), backward(len, 0), vec(len, 0);
        forward[0] = nums[0];
        backward[len-1] = nums[len-1];
        for (int i=1, j=len-2; i<len; i++, j--) {
            forward[i] = forward[i-1]+nums[i];
            backward[j] = backward[j+1]+nums[j];
        }
        for (int i=0; i<len; i++) vec[i] = abs(forward[i]/(i+1) - getVal(backward, nums, i, len));
        int minimun = INT_MAX, res = 0;
        for (int i=0; i<len; i++) {
            if (vec[i] < minimun) {
                minimun = vec[i];
                res = i;
            }
        }
        return res;
    }
};
