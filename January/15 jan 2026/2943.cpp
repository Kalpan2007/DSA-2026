
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        auto longest = [](vector<int>& a) {
            sort(a.begin(), a.end());
            int best = 1, cur = 1;
            for (int i = 1; i < a.size(); i++) {
                if (a[i] == a[i - 1] + 1) cur++;
                else cur = 1;
                best = max(best, cur);
            }
            return best + 1;
        };
        int h = longest(hBars);
        int v = longest(vBars);
        int side = min(h, v);
        return side * side;
    }
};