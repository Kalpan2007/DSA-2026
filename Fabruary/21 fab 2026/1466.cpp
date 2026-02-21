class Solution {
public:
    void dfs(int u, int parent, unordered_map<int, vector<pair<int, int>>>& adj,
             int &count) {
                for(auto &p : adj[u]){
                    int v = p.first;
                    int check = p.second;

                    // parent does not selfnode
                    if(v!=parent){
                        if(check==1){
                            count++;
                        }
                        dfs(v , u , adj , count);
                    }
                }
             }

    int minReorder(int n, vector<vector<int>>& connections) {
        int count = 0;

        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& vec : connections) {
            int a = vec[0];
            int b = vec[1];

            adj[a].push_back({b, 1}); // original edge
            adj[b].push_back({a, 0}); // which i make for traversal both side
        }

        dfs(0, -1, adj, count);
        return count;
    }
};