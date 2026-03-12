class DSU {
public:
    vector<int> p, r;

    DSU(int n) {
        p.resize(n);
        r.resize(n, 1);

        for(int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int fp(int x) {
        if(x == p[x])
            return x;

        return p[x] = fp(p[x]);
    }

    bool uni(int a, int b) {
        int pa = fp(a);
        int pb = fp(b);

        if(pa == pb)
            return false;

        if(r[pa] > r[pb]) {
            p[pb] = pa;
        } 
        else if(r[pa] < r[pb]) {
            p[pa] = pb;
        } 
        else {
            p[pa] = pb;
            r[pb]++;
        }

        return true;
    }
};

class Solution {
public:

    bool ok(int n, vector<vector<int>>& e, int k, int mid) {
        DSU dsu(n);

        vector<vector<int>> up;

        for(auto &ed : e) {
            int u = ed[0];
            int v = ed[1];
            int s = ed[2];
            int m = ed[3];

            if(m == 1) {
                if(s < mid)
                    return false;

                dsu.uni(u, v);
            } 
            else {
                if(s >= mid) {
                    dsu.uni(u, v);
                } 
                else if(2*s >= mid) {
                    up.push_back({u, v});
                }
            }
        }

        for(auto &ed : up) {
            int u = ed[0];
            int v = ed[1];

            if(dsu.fp(u) != dsu.fp(v)) {
                if(k <= 0)
                    return false;

                dsu.uni(u, v);
                k--;
            }
        }

        int root = dsu.fp(0);

        for(int i = 1; i < n; i++) {
            if(dsu.fp(i) != root)
                return false;
        }

        return true;
    }

    int maxStability(int n, vector<vector<int>>& e, int k) {

        DSU dsu(n);

        for(auto &ed : e) {
            int u = ed[0];
            int v = ed[1];
            int m = ed[3];

            if(m == 1) {
                if(dsu.fp(u) == dsu.fp(v))
                    return -1;

                dsu.uni(u, v);
            }
        }

        int ans = -1;

        int l = 1;
        int r = 2 * 1e5;

        while(l <= r) {

            int mid = l + (r - l) / 2;

            if(ok(n, e, k, mid)) {
                ans = mid;
                l = mid + 1;
            } 
            else {
                r = mid - 1;
            }
        }

        return ans;
    }
};