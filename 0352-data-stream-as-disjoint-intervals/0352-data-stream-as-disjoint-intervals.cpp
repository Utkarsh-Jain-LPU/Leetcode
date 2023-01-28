class SummaryRanges {
public:
    set<int> s;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        if (s.size() == 0) return res;
        int start = INT_MIN, end = INT_MIN;
        for (auto it=s.begin(); it!=s.end(); it++) {
            if (start == INT_MIN) start = *it, end = *it;
            else if (*it == end+1) end = *it;
            else {
                vector<int> v;
                v.push_back(start);
                v.push_back(end);
                res.push_back(v);
                start = end = *it;
            }
        }
        if (start != INT_MIN) {
            vector<int> v;
            v.push_back(start);
            v.push_back(end);
            res.push_back(v);
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
