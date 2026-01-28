class Solution {
public:
    int minCost(vector<vector<int>>& grid, int K) {
        int n = grid.size(), m = grid[0].size();
        int MAX = INT_MAX;
        int range = 10000;

        // dp for current p
        vector<vector<int>> dp(n, vector<int>(m, MAX));

        vector<int> bestPrefix(range + 1, MAX);

        for (int p = 0; p <= K; p++) {
            vector<int> bestCurrent(range + 1, MAX);
            vector<vector<int>> newDp(n, vector<int>(m, MAX));

            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    if (i == n - 1 && j == m - 1) {
                        newDp[i][j] = 0;
                    } else {
                        int ans = MAX;

                        if (i + 1 < n)
                            ans = min(ans, grid[i + 1][j] + newDp[i + 1][j]);
                        if (j + 1 < m)
                            ans = min(ans, grid[i][j + 1] + newDp[i][j + 1]);
                        if (p > 0)
                            ans = min(ans, bestPrefix[grid[i][j]]);

                        newDp[i][j] = ans;
                    }
                    bestCurrent[grid[i][j]] = min(bestCurrent[grid[i][j]], newDp[i][j]);
                }
            }

            bestPrefix.assign(range + 1, MAX);
            bestPrefix[0] = bestCurrent[0];
            for (int r = 1; r <= range; r++) {
                bestPrefix[r] = min(bestPrefix[r - 1], bestCurrent[r]);
            }

            dp.swap(newDp);
        }

        return dp[0][0];
    }
};
