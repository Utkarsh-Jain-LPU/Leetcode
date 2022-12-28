class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        multiset<int, greater<int>> ms;
        for (int pile : piles) ms.insert(pile);
        while (k--) {
            int pile = *(ms.begin());
            ms.erase(ms.begin());
            ms.insert(ceil(pile/2.0));
        }
        int count = 0;
        for (auto it : ms) count += it;
        return count;
    }
};
