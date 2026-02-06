class Solution {
public:
    int strStr(string h, string n) {
        int l = n.length();
        for(int i = 0 ; i < h.length();i++){
            string s = h.substr(i,l);
            if(s==n) return i;
        }
        return -1;
    }
};