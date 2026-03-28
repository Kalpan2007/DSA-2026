class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<long long> row_sum(m, 0), col_sum(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                row_sum[i] += val;
                col_sum[j] += val;
            }
        }

        vector<long long> row_prefix(m + 1, 0), col_prefix(n + 1, 0);

        for (int i = 0; i < m; i++) {
            row_prefix[i + 1] = row_prefix[i] + row_sum[i];
        }

        for (int i = 0; i < n; i++) {
            col_prefix[i + 1] = col_prefix[i] + col_sum[i];
        }

        long long total_sum = row_prefix[m];

        if (total_sum % 2 != 0) return false;

        long long target = total_sum / 2;

        for (int i = 1; i < m; i++) {
            if (row_prefix[i] == target) return true;
        }

        for (int i = 1; i < n; i++) {
            if (col_prefix[i] == target) return true;
        }

        return false;
    }
};