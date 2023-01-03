class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n-1;
        vector<int> res(2);
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                res[0] = i+1;
                res[1] = j+1;
                break;
            } else if (sum < target) i++;
            else j--;
        }
        return res;
    }
};
