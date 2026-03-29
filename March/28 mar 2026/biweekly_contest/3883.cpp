class Solution {
public:
    const int mod = 1e9 + 7;
    int digitSumOf(int n){
        int s = 0;
        while(n > 0){
            s += n % 10;
            n /=10;
        }
        return s;
    }
    int countArrays(vector<int>& digitSum) {
      int n = digitSum.size();
        for(int i = 0 ; i < digitSum.size() ; i++){
            if(digitSum[i] > 31) return 0;
        }

        vector<vector<int>> cadidates(51);

        for(int i = 0 ; i <=5000 ; i++){
            int s = digitSumOf(i);
            if( s <=50) cadidates[s].push_back(i);
        }   

        vector<long long> dp(5001 , 0);

        for(int v : cadidates[digitSum[0]]){
            dp[v] = 1;
        }

        for(int i = 1 ; i < n ; i++){
            vector<long long> pre(5002 , 0);
            for(int j = 0 ; j <= 5000 ; j++){
                pre[j+1] = (pre[j] + dp[j] % mod);
            }
            
            vector<long long> newDp(5001 , 0);
            for(int j : cadidates[digitSum[i]]){
                newDp[j] = pre[j+1];
            }
            dp = newDp;
        }
        long long ans = 0;
        for(int i = 0 ; i <= 5000 ; i++){
            ans = (ans + dp[i]) % mod;
        }
        return (int)ans;
    }
};