class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (digits[n-1] != 9) {
            digits[n-1]++;
            return digits;
        }
        digits[n-1] = 0;
        int x = n-2;
        while (x >= 0 && digits[x]+1 > 9) {
            digits[x] = 0;
            x--;
        }
        if (x >= 0) {
            digits[x]++;
            return digits;
        }
        vector<int> v;
        v.push_back(1);
        for (auto i : digits) {
            v.push_back(i);
        }
        return v;
    }
};
