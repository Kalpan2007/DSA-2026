class Solution {
public:
    string reverseByType(string s) {
        string a = "";
        string b = "";
        int n = s.length();

        for(int i = 0;i<n;i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                a += s[i];
            }else{
                b += s[i];
            }
        }

        int j = a.length()-1;
        int k = b.length()-1;

        for(int i = 0 ; i < n ; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] = a[j];
                j--;
            }else{
                s[i] = b[k];
                k--;
            }
        }
        return s;
    }
};