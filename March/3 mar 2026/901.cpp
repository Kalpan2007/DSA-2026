class StockSpanner {
public:
    vector<int> prices;
    StockSpanner() {}

    int next(int price) {
        int ans = 1;
        int i = prices.size() - 1;

        while (i >= 0 && prices[i] <= price) {
            ans++;
            i--;
        }

        prices.push_back(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */