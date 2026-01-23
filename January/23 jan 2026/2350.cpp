class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> rowMap; 
        
        for (auto &row : grid) rowMap[row]++;

        int ans = 0;
        for (int c = 0; c < n; c++) {
            vector<int> col;
            for (int r = 0; r < n; r++) col.push_back(grid[r][c]);
            if (rowMap.count(col)) ans += rowMap[col];
        }
        return ans;
    }
};