class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;
        for(int i = n-1;i>=0;i--){
            int curr = mp[s[i]];
            if(i < n-1 && curr < mp[s[i+1]]){
                ans -= curr;
            }else{
                ans += curr;
            }
        }
        return ans;
    }
};