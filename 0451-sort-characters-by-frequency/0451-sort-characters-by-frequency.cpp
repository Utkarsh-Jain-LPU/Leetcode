class Solution {
public:
    static bool compare(pair<char, int>& A, pair<char, int>& B) {
        return A.second > B.second;
    }
    string frequencySort(string s) {
        string str = "";
        map<char, int> mp;
        for (char ch : s) mp[ch]++;
        vector<pair<char, int>> vec;
        for (auto it : mp) vec.push_back(it);
        sort(vec.begin(), vec.end(), compare);
        for (auto it : vec) {
            for (int i=0; i<it.second; i++) str += it.first;
        }
        return str;
    }
};
