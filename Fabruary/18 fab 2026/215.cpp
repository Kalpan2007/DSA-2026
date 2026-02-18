class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int, int, greater<int>> mp;
        for(int x : nums){
            mp[x]++;
        }
        int count = 0;
        for(auto it : mp){
            count += it.second;   
            if(count >= k){
                return it.first;  
            }
        }
        return -1;
    }
};
