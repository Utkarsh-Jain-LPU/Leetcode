class Solution {
public:
    int countOdds(int low, int high) {
        int n = high-low+1;
        if (n%2 != 0) {
            return (low%2) == 0 ? n/2 : n/2 + 1;
        }
        return n/2;
    }
};
