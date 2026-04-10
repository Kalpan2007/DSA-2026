class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
    int rows = coins.size();
    int cols = coins[0].size();
    const long long NEG_INF = LLONG_MIN / 2;
    vector<vector<array<long long, 3>>> dp(
        rows, vector<array<long long, 3>>(cols, {NEG_INF, NEG_INF, NEG_INF})
    );

    dp[0][0][0] = coins[0][0];
    if (coins[0][0] < 0)
        dp[0][0][1] = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0) continue;
            int cell = coins[i][j];
            for (int k = 0; k <= 2; k++) {
                long long best = NEG_INF;
                if (i > 0 && dp[i-1][j][k] != NEG_INF)
                    best = max(best, dp[i-1][j][k]);
                if (j > 0 && dp[i][j-1][k] != NEG_INF)
                    best = max(best, dp[i][j-1][k]);
                if (best == NEG_INF) continue;
                dp[i][j][k] = max(dp[i][j][k], best + cell);
                if (cell < 0 && k < 2)
                    dp[i][j][k+1] = max(dp[i][j][k+1], best);
            }
        }
    }

    long long ans = NEG_INF;
    for (int k = 0; k <= 2; k++)
        ans = max(ans, dp[rows-1][cols-1][k]);
    return ans;
    }
};