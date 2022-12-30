class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = 0;
        int buy = INT_MIN;
        for (int price : prices) {
            sell = max(sell, buy+price);
            buy = max(buy, -price);
        }
        return sell;
    }
};
