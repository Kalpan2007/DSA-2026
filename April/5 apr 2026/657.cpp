class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> index = {0,0};
        int n = moves.size();
        int start = 0;
        while(start < n){
            if(moves[start]=='U'){
                index[0]++;
            }else if(moves[start]=='D'){
                index[0]--;
            }else if(moves[start]=='R'){
                index[1]++;
            }else{
                index[1]--;
            }
            start++;
        }
        if(index[0]==0 && index[1]==0){
            return true;
        }else{
            return false;
        }
    }
};