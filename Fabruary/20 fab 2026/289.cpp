class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        
        vector<vector<int>> ans = board;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int count = 0;

                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {

                        if (x == i && y == j) continue;

                        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 1) {
                            count++;
                        }
                    }
                }

                if (board[i][j] == 1) {
                    if (count < 2 || count > 3)
                        ans[i][j] = 0;
                    else
                        ans[i][j] = 1;
                } else {
                    if (count == 3)
                        ans[i][j] = 1;
                    else
                        ans[i][j] = 0;
                }
            }
        }

       
        board = ans;
    }
};