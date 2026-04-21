class Solution {
private:
    class DSU {
    private:
        vector<int> parent;

    public:
        DSU(int n) {
            parent.resize(n);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int findUnion(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = findUnion(parent[x]);
        }

        void unite(int a, int b) {
            int x = findUnion(a);
            int y = findUnion(b);

            if (x != y) {
                parent[y] = x;
            }
        }
    };

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        DSU dsu(n);

        for (auto& e : allowedSwaps) {
            dsu.unite(e[0], e[1]);
        }

        unordered_map<int, unordered_map<int, int>> mp;

        for (int i = 0; i < n; i++) {
            int v1 = source[i];
            int c1 = dsu.findUnion(i);

            mp[c1][v1]++;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int parent = dsu.findUnion(i);

            if (mp[parent][target[i]] > 0) {
                mp[parent][target[i]]--;
            } else {
                cnt++;
            }
        }

        return cnt;
    }
};