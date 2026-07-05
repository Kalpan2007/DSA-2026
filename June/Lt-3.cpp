class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans =0;
        unordered_map<char , int> mp;
        int left = 0;
        int right = 0;
        for(;right < s.size();right++){
            int idx =-1;
            if(mp.count(s[right])){
                idx = mp[s[right]];
            }

            if(idx != -1 && idx >= left){
                ans = max(ans , right - left);
                left = idx+1;
                mp[s[right]] = idx;
            }
           
            mp[s[right]] = right;
        }
        return max(ans , right - left);
    }
};