class Solution {
public:
    bool p(string& t , int i , int j){
        for(; i < j;i++ , j--){
            if(t[i]!=t[j]) return 0;

        }
                    return 1;
    }
    int almostPalindromic(string s) {
        int n = s.size();
        int i , j , l , r;
        for(int len = n ; len >=2 ; len--){
            for(i = 0;i<=n-len;i++){
                j = i + len -1;
                l=i;
                r=j;
                while(l < r && s[l]==s[r]){
                    l++;
                    r--;
                }
                if(l >=r || p(s ,l+1 , r) || p(s , l , r-1)){
                    return len;
                }
            }
        }
        return 0;
    }
};