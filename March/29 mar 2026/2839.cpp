class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool first = false , second = false , third = false , fourth = false;
        
        if(s1[0]==s2[0]) first = true;
        if(s1[1]==s2[1]) second = true;
        if(s1[2]==s2[2]) third = true;
        if(s1[3]==s2[3]) fourth = true;

        if(!first || !third){
            swap(s2[0],s2[2]);
            if(s1[0]==s2[0]) first = true;
            if(s1[2]==s2[2]) third = true;
        }

        if(!second || !fourth){
            swap(s2[1] , s2[3]);
            if(s1[1]==s2[1]) second = true;
            if(s1[3]==s2[3]) fourth = true;
        }

        if(first && second && third && fourth) return true;
        return false;
    }
};