class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        int i = m-1;
        int j = n-1;
        int x = m+n-1;
        while (i >= 0 && j >= 0) {
            if (nums2[j] > nums1[i]) {
                nums1[x--] = nums2[j];
                j--;
            } else {
                nums1[x--] = nums1[i];
                i--;
            }
        }
        while (j >= 0) {
            nums1[j] = nums2[j];
            j--;
        }
    }
};
