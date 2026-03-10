class Solution {
public:
    int solve(string& word1, string& word2, int i, int j,vector<vector<int>>& dp) {

        int n = word1.length();
        int m = word2.length();

        if (i == n)
            return m - j;
        if (j == m)
            return n - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j]) {
            return dp[i][j] = solve(word1, word2, i + 1, j + 1, dp);
        }

        int r1 = n - i;
        int r2 = m - j;
        int lower_bond = abs(r1 - r2);

        int insert_op = 1 + solve(word1, word2, i, j + 1, dp);
        int delete_op = 1 + solve(word1, word2, i + 1, j, dp);
        int replace_op = 1 + solve(word1, word2, i + 1, j + 1, dp);

        return dp[i][j] = min({insert_op, delete_op, replace_op});
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};