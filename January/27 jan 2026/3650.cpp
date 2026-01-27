class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int,int>>> mp;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            mp[u].push_back({v, wt});
            mp[v].push_back({u, 2 * wt});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ans(n, INT_MAX);

        ans[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {   
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();          

            if (node == n - 1) {
                return d;
            }

            for (auto &p : mp[node]) {
                int adjacent_node = p.first;
                int dist = p.second;

                if (d + dist < ans[adjacent_node]) {
                    ans[adjacent_node] = d + dist;
                    pq.push({d + dist, adjacent_node});
                }
            }
        }

        return -1;
    }
};