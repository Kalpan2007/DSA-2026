class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        double low = 1e18, high = -1e18;

        for (auto &s : squares) {
            double y = s[1], l = s[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        for (int i = 0; i < 80; i++) {
            double mid = (low + high) / 2.0;
            double areaBelow = 0;

            for (auto &s : squares) {
                double y = s[1], l = s[2];
                if (mid <= y) continue;
                if (mid >= y + l) areaBelow += l * l;
                else areaBelow += l * (mid - y);
            }

            if (areaBelow * 2 < totalArea)
                low = mid;
            else
                high = mid;
        }
        return low;
    }
};