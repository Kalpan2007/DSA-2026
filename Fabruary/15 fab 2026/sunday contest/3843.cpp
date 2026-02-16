class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x : nums){
            mp[x]++;
        }

        unordered_map<int,int> mp2;
        for(auto const& [k,v] : mp){
            mp2[v]++;
        }

        for(int x : nums){
            int c = mp[x];
            if(mp2[c]==1){
                return x;
            }
        }
        return -1;
    }
};