class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si = 0;
        int ti = 0;
        while(ti < t.size()){
            if(s[si]==t[ti]){
                si++;
            }
            ti++;
        }
        return si==s.size();
    }
};