class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0;
        int r = h.size() - 1;
        int ans = 0;

        while (l < r) {
            int width = r - l;
            int height = min(h[l], h[r]);
            ans = max(ans, width * height);

            // Move the smaller height pointer
            if (h[l] < h[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
