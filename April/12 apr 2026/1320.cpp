class Solution {
public:
int dp[301][27][27];
    int cal(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int solve(string &s, int i, int f1, int f2) {
        if (i == s.size()) return 0;
       if (dp[i][f1][f2] != -1) return dp[i][f1][f2];
        int curr = s[i] - 'A';

        int cost1 = 0;
        if (f1 == 26) cost1 = solve(s, i + 1, curr, f2);
        else cost1 = cal(f1, curr) + solve(s, i + 1, curr, f2);

        int cost2 = 0;
        if (f2 == 26) cost2 = solve(s, i + 1, f1, curr);
        else cost2 = cal(f2, curr) + solve(s, i + 1, f1, curr);

         return dp[i][f1][f2] = min(cost1, cost2);
    }

    int minimumDistance(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 26, 26); 
    }
};