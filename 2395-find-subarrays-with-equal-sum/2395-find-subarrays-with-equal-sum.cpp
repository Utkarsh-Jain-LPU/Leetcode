class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for (int i=1; i<n; i++) {
            int t = nums[i]+nums[i-1];
            mp[t]++;
            if (mp[t] >= 2) return true;
        }
        return false;
    }
};
