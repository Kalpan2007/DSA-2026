class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        
        int left = 0;
        int right = m.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (t > m[mid][m[0].size() - 1]) {
                left = mid + 1;
            } 
            else if (t < m[mid][0]) {
                right = mid - 1;
            } 
            else {
                int leftIn = 0;
                int rightIn = m[0].size() - 1;
                while (leftIn <= rightIn) {
                    int midIn = leftIn + (rightIn - leftIn) / 2;
                    if (m[mid][midIn] == t) return true;
                    else if (m[mid][midIn] < t) leftIn = midIn + 1;
                    else rightIn = midIn - 1;
                }
                return false;
            }
        }
        return false;
    }
};
