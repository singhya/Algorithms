class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2)
            return 0;
        int buy = -prices[0];
        int sell = 0;
        int sell_prev = 0;
        int i=1;
        for(;i<prices.size();i++){
            int prev_buy = buy;
            buy = max(prev_buy,sell_prev-prices[i]);
            sell_prev = sell;
            sell = max(sell,prev_buy+prices[i]);
        }
        return sell;
    }
};
