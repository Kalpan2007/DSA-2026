class Solution {
public:
    int hIndex(vector<int>& c) {
        int ans = 0;
        int n = c.size();
        vector<int> count(n+1,0);
        for(int i = 0;i<n;i++){
            if(c[i] < n){
                count[c[i]]++;
            }else{
                count[n]++;
            }
        }
        for(int i = n ; i >=0 ;i--){
            ans += count[i];
            if(ans >= i){
                return i;
            }
        }
        return 0;
    }
};