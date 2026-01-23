class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zerocount = 0;
        int ml =0;
        int i = 0;
        for(int j = 0;j<nums.size();j++){
            if(nums[j]==0) zerocount++;
            while(zerocount > 1){
                if(nums[i]==0){
                    zerocount--;
                }   
                i++;
            }
            ml = max(ml , j-i);
        }
        return ml;
    }
};