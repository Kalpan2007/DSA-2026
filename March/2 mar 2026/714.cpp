class Solution {
public:
    int dfs(int i, int holding, vector<int>& prices, int fee,
            vector<vector<int>>& dp) {

        if (i == prices.size())
            return 0;
        if (dp[i][holding] != -1)
            return dp[i][holding];

        int ans = dfs(i + 1, holding, prices, fee, dp);

        if (holding) {
            ans = max(ans, prices[i] - fee + dfs(i + 1, 0, prices, fee, dp));
        } else {
            ans = max(ans, -prices[i] + dfs(i + 1, 1, prices, fee, dp));
        }

        return dp[i][holding] = ans;
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dfs(0, 0, prices, fee, dp);
    }
};