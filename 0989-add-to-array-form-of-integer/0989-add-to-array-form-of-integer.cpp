class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size()-1, carry = 0;
        vector<int> res;
        while (k > 0 && n >= 0) {
            int x = num[n]+(k%10)+carry;
            if (x > 9) carry = x/10;
            else carry = 0;
            res.insert(res.begin(), x%10);
            k = k/10;
            n--;
        }
        while (n >= 0) {
            int x = num[n--]+carry;
            if (x > 9) carry = x/10;
            else carry = 0;
            res.insert(res.begin(), x%10);
        }
        while (k > 0) {
            int x = (k%10)+carry;
            if (x > 9) carry = x/10;
            else carry = 0;
            res.insert(res.begin(), x%10);
            k = k/10;
        }
        if (carry != 0) res.insert(res.begin(), carry);
        return res;
    }
};
