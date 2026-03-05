class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int swz = 0;
        int swo = 0;

        for(int i = 0 ; i < n; i++){
            if(i%2==0){
                if(s[i]=='0'){
                    swo++;
                }else{
                    swz++;
                }
            }else{
                if(s[i]=='0') {
                    swz++;
                }else{
                    swo++;
                }
            }
        }
        return min(swo , swz);
    }
};