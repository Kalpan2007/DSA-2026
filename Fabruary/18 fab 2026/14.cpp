class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans = "";
        sort(v.begin(), v.end());
        int n = v.size();
        string f = v[0];
        string l = v[n - 1];
        for (int i = 0; i < min(f.size(), l.size()); i++) {
            if (f[i] != l[i]) {
                return ans;
            }
            ans += f[i];
        }
        return ans;
    }
};