class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        map<int, int> m;
        int lastSum = 0;
        for (int num : nums) {
            lastSum += num;
            if (lastSum == k) count++;
            count += m[lastSum-k];
            m[lastSum]++;
        }
        return count;
    }
};
