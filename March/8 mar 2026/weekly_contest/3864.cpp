class Solution {
public:
    map<pair<int, int> , long long> memo;
    vector<int> pref;
    long long ecost , fcost;
    long long solve(int start , int l){
        if(memo.count({start , l})){
            return memo[{start , l}];
        }
        int x = pref[start + l] - pref[start];
        long long curr;
        if(x==0){
            curr = fcost;
        }else{
            curr = (long long)l * x * ecost;
        }

        if(l %2==0){
            int half = l / 2;
            long long split = solve(start , half) + solve(start+half , half);
            curr = min(curr , split);
        }
        return memo[{start , l}] = curr;
    }
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        ecost = encCost;
        fcost = flatCost;
        memo.clear();

        pref.assign(n+1,0);
        for(int i = 0;i<n;i++){
            pref[i+1]= pref[i] + (s[i]-'0');
        }
        return solve(0,n);
    }
};