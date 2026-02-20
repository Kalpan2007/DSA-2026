class Solution {
public:
    void dfs(int node, vector<vector<int>>& mat, vector<int>& vec) {
        vec[node] = 1;
        for (int i = 0; i < mat.size(); i++) {
            if (mat[node][i] == 1 && !vec[i]) {
                dfs(i, mat, vec);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vec(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vec[i]) {
                count++;
                dfs(i, isConnected, vec);
            }
        }
        return count;
    }
};