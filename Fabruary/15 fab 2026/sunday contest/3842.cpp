class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& b) {
        bool s[101] = {false};
        vector<int> r;

        for(int x : b){
            s[x] =! s[x];
        }
            for(int i = 0;i<= 100;i++){
                if(s[i]){
                    r.push_back(i);
                }
            }
        return r;
    }
};