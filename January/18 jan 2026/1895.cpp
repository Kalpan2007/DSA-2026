class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rowCumSum(m, vector<int>(n, 0));
        vector<vector<int>> colCumSum(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    rowCumSum[i][j] = grid[i][j];
                } else {
                    rowCumSum[i][j] = rowCumSum[i][j - 1] + grid[i][j];
                }

                if (i == 0) {
                    colCumSum[i][j] = grid[i][j];
                } else {
                    colCumSum[i][j] = colCumSum[i - 1][j] + grid[i][j];
                }
            }
        }
        for (int side = min(m, n); side > 1; side--) {
            for (int i = 0; i + side - 1 < m; i++) {
                for (int j = 0; j + side - 1 < n; j++) {
                    int targetSum = rowCumSum[i][j+side-1]-(j>0?rowCumSum[i][j-1]:0);
                    bool allSame=true;
                    for(int r=i+1;r<i+side;r++){
                        int sum = rowCumSum[r][j+side-1]-(j>0?rowCumSum[r][j-1]:0);
                        if ( sum!= targetSum){
                            allSame=false;
                            break;
                        }
                    }
                    if(allSame==false){
                        continue;
                    }
                    for(int c=j;c<j+side;c++){
                        int sum=colCumSum[i+side-1][c]-(i>0?colCumSum[i-1][c]:0);
                        if(sum!=targetSum){
                            allSame=false;
                            break;
                        }
                    }
                    if(allSame==false){
                        continue;
                    }
                    int diag=0;
                    int antiDiag=0;
                    for (int k=0;k<side;k++){
                        diag += grid[i+k][j+k];
                        antiDiag += grid[i+k][j+side-1-k];
                    }
                    if(diag==targetSum && antiDiag==targetSum){
                        return side;
                    }
                }
            }
        }
        return 1;
    }
};