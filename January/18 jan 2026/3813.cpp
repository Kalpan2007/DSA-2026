class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0;
        int c =0;
        for(char x: s){
            if(x >= 'a' && x<='z'){
                if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
                    v++;
                }else{
                    c++;
                }
            }
        }
        if(c==0) return 0;
        return v/c;
    }
};