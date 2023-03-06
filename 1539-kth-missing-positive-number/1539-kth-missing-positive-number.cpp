class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int num = 1, i = 0;
        while (k > 0 && i < n) {
            if (arr[i] == num) i++;
            else k--;
            num++;
        }
        if (i < n) return num-1; 
        return num+k-1;
    }
};
