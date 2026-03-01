class Solution {
public:
    bool is_vowel(char c){
        if(c == 'a' || c == 'e' ||c=='i' ||c=='o'||c=='u') return true;

        return false;
    }
    string trimTrailingVowels(string s) {
        for(int i = s.size()-1 ; i >= 0 ; i--){
            if(is_vowel(s[i])){
                
                    s.pop_back();
                
            }else{
                break;
            }
        }
        return s;
    }
};