class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int c) {
        if (c == 0) return true;
        int n = flowerbed.size();
        for (int i=0; i<n; i++) {
            if (flowerbed[i] == 1) continue;
            bool b1 = false, b2 = false;
            if ((i-1 >= 0 && flowerbed[i-1] == 0) || i-1 < 0) b1 = true;
            if ((i+1 < n && flowerbed[i+1] == 0) || i+1 >= n) b2 = true;
            if (b1 && b2) {
                flowerbed[i] = 1;
                c--;
                if (c <= 0) return true;
            }
        }
        return false;
    }
};
