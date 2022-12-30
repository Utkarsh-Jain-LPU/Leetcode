class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        map<int, int> m;
        for (auto i : nums) m[i] += i;
        vector<int> vec(n, 0);
        vec[1] = m[1];
        vec[2] = m[2];
        for(int i=3; i<n; i++) vec[i] = max(m[i]+vec[i-2], m[i]+vec[i-3]);
        return max(vec[9999], vec[10000]);
    }
};
