class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        vector<int> mp(128,0);
        int count = t.size();
        int start = 0;
        int end = 0;
        int min_l = INT_MAX;
        int start_idx = 0;

        for(char c : t){
            mp[c]++;
        }

        while(end < s.size()){
            if(mp[s[end++]]-- > 0){
                count--;
            }

            while(count == 0){
                if(end - start < min_l){
                    start_idx = start;
                    min_l = end - start; 
                }

                if(mp[s[start++]]++ == 0){
                    count++;
                }
            }
        }

        return min_l== INT_MAX ? "" :s.substr(start_idx,min_l);
    }
};