class Solution {
public:
    bool checkOnesSegment(string s) {
        bool seen = false;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                if(seen) return false;  
                seen = true;
                while(i < s.size() && s[i] == '1'){
                    i++;
                }
                i--; 
            }
        }
        return true;
    }
};