class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = 0;
        int buy = INT_MIN, prev_sell = 0;
        for (int price : prices) {
            int temp = sell;
            sell = max(sell, buy+price);
            buy = max(buy, prev_sell-price);
            prev_sell = temp;
        }
        return sell;
    }
};
