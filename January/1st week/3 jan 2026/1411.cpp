class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        
        long long a = 6; 
        long long b = 6; 
        
        for(int i = 2; i <= n; i++) {
            long long newa = (a*2 + b*2) % MOD;
            long long newb = (a*2 + b*3) % MOD;
            
            a = newa;
            b = newb;
        }
        
        return (a + b) % MOD;
    }
};
