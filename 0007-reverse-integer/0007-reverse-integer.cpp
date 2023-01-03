class Solution {
public:
    int reverse(int x) {
        int sign = (x > 0) ? 1 : -1;
        x = abs(x);
        int res = 0, digit = 0;
        while (x > 0) {
            int temp = x%10;
            if (digit == 9) {
                if (res > 214748364) return 0;
            }
            res = (res*10)+temp;
            x /= 10;
            digit++;
        }
        return res*sign;
    }
};
