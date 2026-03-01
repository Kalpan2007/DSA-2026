class Solution {
public:
    string mergeCharacters(string s, int k) {
        while(true){
            bool merged = false;
            int n = s.size();

            for(int i = 0;i<n && !merged ; i++ ){
                for(int j = i+1 ; j < n ; j++){
                    if(s[i]==s[j] && j - i <=k){
                        s.erase(j , 1);
                        merged = true;
                        break;
                    }
                }
            }
            if(!merged) break;
        }
        return s;
    }
};