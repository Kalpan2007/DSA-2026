class Solution {
public:
    long long countPairs(vector<string>& words) {
        vector<string> vec1 = words;
        int n = vec1.size();
        long long ans = 0;
        unordered_map<string,long long> mp;

        for(string &s : vec1){
            string p = "";
            for(int i = 0;i<s.size();i++){
                int dif = ( s[i]-s[0] + 26 ) % 26;
                p += to_string(dif) + "#";
            }
            mp[p]++;
        }
        for(auto it : mp){
            long long k = it.second;
            ans += k * (k-1) /2;
        }
        return ans;
    }
};