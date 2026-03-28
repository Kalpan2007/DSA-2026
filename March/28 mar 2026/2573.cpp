class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, ' ');
        
        char nextChar = 'a';
        for (int i = 0; i < n; i++) {
            if (word[i] != ' ') continue;
            if (nextChar > 'z') return "";
            word[i] = nextChar++;
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) word[j] = word[i];
            }
        }
        
        vector<vector<int>> check(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] == word[j]) {
                    if (i == n - 1 || j == n - 1)
                        check[i][j] = 1;
                    else
                        check[i][j] = check[i+1][j+1] + 1;
                } else {
                    check[i][j] = 0;
                }
                if (check[i][j] != lcp[i][j]) return "";
            }
        }
        
        return word;
    }
};