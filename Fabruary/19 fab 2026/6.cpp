class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        int cols = n;
        vector<vector<char>> mat(numRows, vector<char>(cols, '\0'));

        int i = 0;
        int col = 0;

        while (i < n) {

            for (int row = 0; row < numRows && i < n; row++) {
                mat[row][col] = s[i++];
            }
            col++;

            for (int row = numRows - 2; row >= 1 && i < n; row--) {
                mat[row][col] = s[i++];
                col++;
            }
        }

        string ans = "";
        for (int r = 0; r < numRows; r++) {
            for (int c = 0; c < cols; c++) {
                if (mat[r][c] != '\0')
                    ans.push_back(mat[r][c]);
            }
        }

        return ans;
    }
};