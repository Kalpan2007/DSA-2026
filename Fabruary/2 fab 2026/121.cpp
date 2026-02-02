class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p =0;
        int min_p = INT_MAX;
        for(int i = 0 ; i < prices.size();i++){
            int pr = prices[i] - min_p;
            p = max(p,pr);
            min_p = min(min_p , prices[i]);
        }
        return p;
    }
};