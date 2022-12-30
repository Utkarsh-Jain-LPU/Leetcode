class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        long sell = 0, buy = INT_MIN;
        for (int price : prices) {
            long old_sell = sell;
            sell = max(sell, buy+price-fee);
            buy = max(buy, old_sell-price);
        }
        return (int)sell;
    }
};
