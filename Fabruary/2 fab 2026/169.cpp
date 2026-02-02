class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        unordered_map<int, int> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            if(it.second > nums.size()/2){
                return it.first;
            }
        }
        return 0;
    }
};