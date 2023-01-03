class Solution {
public:
    string getChars(char ch) {
        switch(ch) {
            case '2':
                return "abc";
            case '3':
                return "def";
            case '4':
                return "ghi";
            case '5':
                return "jkl";
            case '6':
                return "mno";
            case '7':
                return "pqrs";
            case '8':
                return "tuv";
            case '9':
                return "wxyz";
        }
        return " ";
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        vector<string> res;
        if (n == 0) return res;
        string str = getChars(digits[0]);
        for (char ch : str) {
            string s(1, ch);
            res.push_back(s);
        }
        for (int i=1; i<n; i++) {
            string data = getChars(digits[i]);
            vector<string> temp;
            for (int p=0; p<res.size(); p++) {
                string rec = res[p];
                for (int q=0; q<data.length(); q++) {
                    temp.push_back(rec+data[q]);
                }
            }
            res.clear();
            for (string s : temp) res.push_back(s);
        }
        return res;
    }
};
