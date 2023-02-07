class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n <= 2) return n;
        map<int, int> mp;
        int i = 0, res = 0;
        for (int j=0; j<n; j++) {
            mp[fruits[j]]++;
            if (mp.size() <= 2) {
                res = max(res, j-i+1);
                continue;
            }
            while (mp.size() > 2) {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }
        }
        return res;
    }
};
