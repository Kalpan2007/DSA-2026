class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
       int n = costs.size(); 
        vector<pair<int,int>> v(n);
        for(int i = 0;i<n;i++){
            v[i] = { costs[i] , capacity[i] };
        }
        auto l = costs;
        sort(v.begin() , v.end());
        vector<int> m(n);
        m[0] = v[0].second;

        for(int i = 1;i<n;i++){
            m[i] = max(m[i-1] , v[i].second);
        }
        int r = 0;
        int j = n-1;
        for(int i =0;i<n;i++){
            if(v[i].first < budget ) r = max(r,v[i].second);
            while(j >=0 && v[i].first + v[j].first >= budget) j--;
            int k = min(i-1 , j);
            if(k >=0){
                r=max(r,v[i].second+m[k]);
            }
                
                
        }
        return r;
    }
};