class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            unordered_set<char> st;
            for(int j = 0; j <= i ; j++){
                st.insert(s[j]);
            }
            int d = st.size();
            int l = (i+1) %3;
            if(d==l){
                ans++;
            }
        }
        return ans;
    }
};