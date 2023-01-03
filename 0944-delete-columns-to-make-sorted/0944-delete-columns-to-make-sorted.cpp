class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].length();
        int count = 0;
        for (int index=0; index<n; index++) {
            int t = -1;
            for (string& str : strs) {
                int x = str[index]-'a';
                if (x < t) {
                    count++;
                    break;
                }
                t = x;
            }
        }
        return count;
    }
};
