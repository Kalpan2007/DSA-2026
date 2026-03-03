#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(),[](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
            }
        );

        int ans = 1;
        long long lastEnd = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > lastEnd) {
                ans++;
                lastEnd = points[i][1];
            }
        }

        return ans;
    }
};