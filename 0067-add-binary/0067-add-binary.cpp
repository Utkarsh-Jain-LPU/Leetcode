class Solution {
public:
    string addBinary(string a, string b) {
        int x = 0;
        int n1 = a.length();
        int n2 = b.length();
        int carry = 0;
        string ans = "";
        while (x < n1 && x < n2) {
            int sum = (a[n1-x-1]-'0') + (b[n2-x-1]-'0') + carry;
            if (sum == 0 || sum == 1) {
                ans = to_string(sum) + ans;
                carry = 0;
            } else if (sum == 2) {
                ans = to_string(0) + ans;
                carry = 1;
            } else {
                ans = to_string(1) + ans;
                carry = 1;
            }
            x++;
        }
        if (n1 > x) {
            while (x < n1) {
                int sum = (a[n1-x-1]-'0') + carry;
                if (sum == 0 || sum == 1) {
                    ans = to_string(sum) + ans;
                    carry = 0;
                } else if (sum == 2) {
                    ans = to_string(0) + ans;
                    carry = 1;
                } else {
                    ans = to_string(1) + ans;
                    carry = 1;
                }
                x++;
            }
        }
        if (n2 > x) {
            while (x < n2) {
                int sum = (b[n2-x-1]-'0') + carry;
                if (sum == 0 || sum == 1) {
                    ans = to_string(sum) + ans;
                    carry = 0;
                } else if (sum == 2) {
                    ans = to_string(0) + ans;
                    carry = 1;
                } else {
                    ans = to_string(1) + ans;
                    carry = 1;
                }
                x++;
            }
        }
        return (carry == 1) ? "1"+ans : ans;
    }
};
