class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int n = height.size();
        int water = 0;
        for (int j=i+1; j<n; j++) {
            if (height[j] > height[i]) {
                water += (j-i-1)*height[i];
                for (int k=i+1; k<j; k++) water -= height[k];
                i = j;
            }
        }
        i = n-1;
        for (int j=n-2; j>=0; j--) {
            if (height[j] >= height[i]) {
                water += (i-j-1)*height[i];
                for (int k=j+1; k<i; k++) water -= height[k];
                i = j;
            }
        }
        return water;
    }
};
