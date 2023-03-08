class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int low = 1, high = 1000000000, k = 0;
        while (low <= high) {
            k = (low + high) / 2;
            long h = 0;
            for (int pile : piles) h += ceil(1.0 * pile / k);
            if (h > H) low = k + 1;
            else high = k - 1;
        }
        return low;
    }
};
