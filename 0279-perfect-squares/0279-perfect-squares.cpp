class Solution {
public:
    int numSquares(int n) {
        vector<int> vec(n+1);
        vec[0] = 0;
        vec[1] = 1;
        for (int i=2; i<=n; i++) {
            int minVal = INT_MAX;
            for (int j=1; j*j<=i; j++) {
                minVal = min(minVal, vec[i-(j*j)]);
            }
            vec[i] = minVal+1;
        }
        return vec[n];
    }
};
