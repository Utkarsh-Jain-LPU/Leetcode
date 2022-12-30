class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> vec(n);
        vec[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0;
        for (int i=1; i<n; i++) {
            vec[i] = min(vec[t2]*2, min(vec[t3]*3, vec[t5]*5));
            if (vec[i] == vec[t2]*2) t2++;
            if (vec[i] == vec[t3]*3) t3++;
            if (vec[i] == vec[t5]*5) t5++;   
        }
        return vec[n-1];
    }
};
