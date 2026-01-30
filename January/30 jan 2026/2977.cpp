class Solution {
public:
    long long minimumCost(string sourceText, string targetText,
                          vector<string>& fromStrings, vector<string>& toStrings,
                          vector<int>& transformCost) {
        int textLength = sourceText.length();

        unordered_map<string, int> stringId;
        int nextId = 0;

        for (const string& s : fromStrings)
            if (!stringId.count(s))
                stringId[s] = nextId++;

        for (const string& s : toStrings)
            if (!stringId.count(s))
                stringId[s] = nextId++;

        const long long INF = 1e15;

        vector<vector<long long>> minCost(nextId,
                                          vector<long long>(nextId, INF));

        for (int i = 0; i < nextId; ++i)
            minCost[i][i] = 0;

        for (int i = 0; i < fromStrings.size(); ++i) {
            int fromId = stringId[fromStrings[i]];
            int toId   = stringId[toStrings[i]];
            minCost[fromId][toId] = min(minCost[fromId][toId],
                                        (long long)transformCost[i]);
        }

        for (int mid = 0; mid < nextId; ++mid)
            for (int start = 0; start < nextId; ++start)
                for (int end = 0; end < nextId; ++end)
                    if (minCost[start][mid] < INF && minCost[mid][end] < INF)
                        minCost[start][end] =
                            min(minCost[start][end],
                                minCost[start][mid] + minCost[mid][end]);

        vector<long long> dp(textLength + 1, INF);
        dp[0] = 0;

        vector<int> possibleLengths;
        for (const string& s : fromStrings)
            possibleLengths.push_back(s.length());

        sort(possibleLengths.begin(), possibleLengths.end());
        possibleLengths.erase(unique(possibleLengths.begin(),
                                     possibleLengths.end()),
                              possibleLengths.end());

        for (int pos = 0; pos < textLength; ++pos) {
            if (dp[pos] == INF) continue;

            if (sourceText[pos] == targetText[pos])
                dp[pos + 1] = min(dp[pos + 1], dp[pos]);

            for (int len : possibleLengths) {
                if (pos + len > textLength) break;

                string sourceSub = sourceText.substr(pos, len);
                string targetSub = targetText.substr(pos, len);

                if (sourceSub == targetSub) dp[pos + len] = min(dp[pos + len], dp[pos]);
                if (stringId.count(sourceSub) && stringId.count(targetSub)) {
                    int fromId = stringId[sourceSub];
                    int toId   = stringId[targetSub];

                    if (minCost[fromId][toId] < INF)
                        dp[pos + len] =
                            min(dp[pos + len], dp[pos] + minCost[fromId][toId]);
                }
            }
        }

        return (dp[textLength] >= INF) ? -1 : dp[textLength];
    }
};
