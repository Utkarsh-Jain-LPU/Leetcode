class Solution {
public:
    int MOD = 1000000007;
    int numTilings(int n) {
        if (n == 1 || n == 2) return n;
        if (n == 3) return 5;
        vector<long> vec(n+1);
        vec[1] = 1;
        vec[2] = 2;
        vec[3] = 5;
        for (int i=4; i<=n; i++) {
            vec[i] = (vec[i-1]*2)+vec[i-3];
            vec[i] = vec[i]%MOD;
        }
        return (int)vec[n];
    }
};
