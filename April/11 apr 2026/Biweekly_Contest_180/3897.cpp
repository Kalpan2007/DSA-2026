class Solution {
public:
    char getchar(int ones , int zeros , int pos){
        if(pos < ones) return '1';
        return '0';
    }
    
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        long long mod = 1e9 + 7;

        vector<pair<int , int>> s;
        for(int i = 0; i < n ; i++){
            s.push_back({nums1[i],nums0[i]});
        }

        sort(s.begin() , s.end(), [&](auto& a , auto& b){
            int la = a.first + a.second;
            int lb = b.first + b.second;
            int total = la + lb;

            for(int i = 0 ; i < total ; i++){
                char ab = (i < la) ? getchar(a.first , a.second , i) : getchar(b.first , b.second, i -la);

                char ba = (i < lb) ? getchar(b.first , b.second , i) : getchar(a.first , a.second , i-lb);

                if(ab!=ba) return ab > ba;
            }
            return false;
        });

        long long ans = 0;
        for(auto& [ones , zeros] : s){
            for(int i = 0;i<ones;i++) ans = (ans*2+1)%mod;
            for(int i = 0;i<zeros;i++) ans = (ans*2)%mod;
        }
        return (int)ans;
    }
};