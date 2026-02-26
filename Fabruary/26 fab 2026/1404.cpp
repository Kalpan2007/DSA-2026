class Solution {
public:
void add_one(string &s){
    int i = s.size() -1;

    while(i >= 0 && s[i]!= '0'){
        s[i] = '0';
        i--;
    }

    if(i < 0){
        s = '1' + s;
    }else{
        s[i] ='1';
    }
}
    int numSteps(string s) {
        int ans = 0;

        while(s.size() > 1){
            int n = s.size();
            if(s[n-1]=='0'){
                s.pop_back();
            }else{
                add_one(s);
            }
            ans++;
        }
        return ans;
    }
};