class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int stock = INT_MIN;
        int cash = 0;
        for(int price : prices){
            stock = max(stock, cash - price);
            cash = max(cash, stock + price - fee);
        }
        return cash;
    }
};
