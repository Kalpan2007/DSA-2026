class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {
        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> d(26, vector<long long>(26, INF));

        for (int i = 0; i < 26; i++) d[i][i] = 0;

        for (int i = 0; i < cost.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            d[u][v] = min(d[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (d[i][k] < INF && d[k][j] < INF) {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
        }

        long long total = 0;
        for (int i = 0; i < source.size(); i++) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            if (s != t) {
                if (d[s][t] >= INF) return -1;
                total += d[s][t];
            }
        }
        return total;
    }
};