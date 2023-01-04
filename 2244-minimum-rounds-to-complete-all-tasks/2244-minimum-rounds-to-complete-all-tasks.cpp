class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> mp;
        for (int task : tasks) mp[task]++;
        int count = 0;
        for (auto [key, value] : mp) {
            if (value == 1) return -1;
            if (value % 3 == 0) {
                count += value/3;
            } else if (value % 3 == 1) {
                count += ((value/3 == 0) ? 0 : value/3 - 1) + 2;
            } else {
                count += value/3 + 1;
            }
        }
        return count;
    }
};
