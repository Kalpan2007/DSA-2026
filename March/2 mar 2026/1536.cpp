class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> vec;
        
        for (int i = 0; i < n; i++) {
            int zeros = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    zeros++;
                } else {
                    break;
                }
            }
            vec.push_back(zeros);
        }

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int need = n - 1 - i;
            int j = i;

        
            while (j < n && vec[j] < need) {
                j++;
            }

            if (j == n) return -1;

            while (j > i) {
                swap(vec[j], vec[j - 1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};