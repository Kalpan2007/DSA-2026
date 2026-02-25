class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int,int>, int>> q;

        int fresh = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
                if(grid[i][j] == 1) fresh++;
            }
        }

        int cnt = 0; 

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();

            ans = max(ans, time);

            
            if(j+1 < m && !vis[i][j+1] && grid[i][j+1] == 1){
                q.push({{i, j+1}, time+1});
                vis[i][j+1] = true;
                cnt++;
            }

            
            if(i+1 < n && !vis[i+1][j] && grid[i+1][j] == 1){
                q.push({{i+1, j}, time+1});
                vis[i+1][j] = true;
                cnt++;
            }

            
            if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == 1){
                q.push({{i-1, j}, time+1});
                vis[i-1][j] = true;
                cnt++;
            }

            
            if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == 1){
                q.push({{i, j-1}, time+1});
                vis[i][j-1] = true;
                cnt++;
            }
        }

        
        if(cnt != fresh) return -1;

        return ans;
    }
};
