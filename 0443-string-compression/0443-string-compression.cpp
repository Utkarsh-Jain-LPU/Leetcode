class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n == 1) return n;
        int i = 0, count = 1, size = 0;
        char ch = chars[i++];
        vector<char> vec;
        vec.push_back(ch);
        while (i < n) {
            if (chars[i] == ch) {
                count++, i++;
                continue;
            }
            vector<char> temp;
            if (count == 1) size += 1;
            else {
                int digits = 0;
                while (count > 0) {
                    int x = count%10;
                    count /= 10;
                    digits++;
                    temp.insert(temp.begin(), x+'0');
                }
                size += digits + 1;
            }
            count = 1;
            ch = chars[i];
            i++;
            vec.insert(vec.end(), temp.begin(), temp.end());
            vec.push_back(ch);
        }
        vector<char> temp;
        if (count == 1) size += 1;
        else {
            int digits = 0;
                while (count > 0) {
                int x = count%10;
                count /= 10;
                digits++;
                temp.insert(temp.begin(), x+'0');
            }
            size += digits + 1;
        }
        vec.insert(vec.end(), temp.begin(), temp.end());
        chars = vec;
        return size;
    }
};
