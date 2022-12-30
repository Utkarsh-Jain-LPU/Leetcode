class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = 0;
        int buy = INT_MIN;
        for (int price : prices) {
            int old_sell = sell;
            sell = max(sell, buy+price);
            buy = max(buy, old_sell-price);
        }
        return sell;
    }
};
