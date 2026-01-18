class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        vector<int> r(26, 0);
        for (char c : s) {
            r[c - 'a'] ++;
        }
        string tl = s;
        string ans = "";
        vector<int> st(26, 0);
        for (char c : s) {
            r[c - 'a']--;
            while(!ans.empty() && ans.back() > c){
                int i = ans.back() - 'a';
                if(st[i] + r[i] > 1){
                    st[i]--;
                    ans.pop_back();
                }else{
                    break;
                }
            }
            ans += c;
            st[c - 'a']++;
        }
        while(!ans.empty()){
            int i = ans.back() - 'a';
            if(st[i] > 1){
                st[i]--;
                ans.pop_back();
            }else{
                break;
            }
        }
        return ans;
    }
};