class Solution {
public:
    string reversePrefix(string s, int k) {
        if(s.size()<=1 || k<=1){
            return s;
        }
        int start = 0;
        int end = k -1;
        while(start < end){
            char temp = s[start];
            s[start] = s[end];
            s[end]= temp;
            start++;
            end--;
        }
        return s;
    }
};