class Solution {
public:
    bool isMatched(map<char, int>& m1, map<char, int>& m2) {
        for (char i='a'; i<='z'; i++) {
            if (m1[i] != m2[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        if (n < m) {
            return false;
        }
        if (m == 1) {
            for (int i=0; i<n; i++) {
                if (s2[i] == s1[0]) {
                    return true;
                }
            }
        }
        map<char, int> mapMain;
        for (char ch : s1) {
            mapMain[ch]++;
        }
        map<char, int> tempMap;
        if (m == n) {
            for (char ch : s2) {
                tempMap[ch]++;
            }
            return isMatched(mapMain, tempMap);
        }
        int lastSum = (mapMain[s2[0]] > 0) ? 1 : 0;
        (mapMain[s2[0]] > 0) ? tempMap[s2[0]]++ : 0;
        for (int i=1; i<n; i++) {
            if (mapMain[s2[i]] > 0) {
                lastSum++;
                tempMap[s2[i]]++;
                if (lastSum == m) {
                    if (isMatched(tempMap, mapMain)) {
                        return true;
                    }
                    lastSum--;
                    tempMap[s2[i-m+1]]--;
                }
            } else {
                lastSum = 0;
                tempMap.clear();
            }
        }
        return false;
    }
};
