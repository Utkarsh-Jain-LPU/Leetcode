class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long res = 0;
        for (int num : nums) {
            if (num == 0) {
                count++;
                continue;
            }
            res += (count*(count+1))/2;
            count = 0;
        }
        res += (count*(count+1))/2;
        return res;
    }
};
