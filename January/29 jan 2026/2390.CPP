class Solution {
public:
    string removeStars(string s) {
        stack<char> store;
        string result = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '*') result += s[i];
            else result.pop_back();
        }
        return result;

    }
};