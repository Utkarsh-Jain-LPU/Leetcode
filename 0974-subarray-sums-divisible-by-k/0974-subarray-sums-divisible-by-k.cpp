class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        mp[0] = 1;
        long sum = 0, count = 0;
        for (int i=0; i<n; i++) {
            sum += nums[i];
            while (sum < 0) sum += k;
            count += mp[sum%k];
            mp[sum%k]++;
        }
        return count;
    }
};
