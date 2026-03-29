class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), parity(n,0);
            iota(parent.begin() , parent.end(),0);

            function<pair<int , int> (int)> findp = [&](int x) -> pair<int,int>{
                if(parent[x]==x) return {x , 0};
                auto [root , p] = findp(parent[x]);
                parity[x] ^= parity[parent[x]];
                parent[x] = root;
                return {root , parity[x]};
            };
            int ans = 0;
            for(auto& e : edges){
                int u = e[0] , v = e[1] , w = e[2];
                auto [rootu , paru] = findp(u);
                auto [rootv , parv] = findp(v);

                if(rootu == rootv){
                    if((paru ^ parv) == w){
                        ans++;
                    }
                }else{
                    parent[rootu]= rootv;
                    parity[rootu] = paru ^ parv ^ w;
                    ans++;
                }
            }
            return ans;
    }
};