class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        int ls = 1;
        for(int i = 0;i<nums.size();i++){
            ans[i] = ls;
            ls *= nums[i];
        }
        int rs = 1;
        for(int j = nums.size()-1 ; j>=0;j--){
            ans[j] *= rs;
            rs *= nums[j];
        }
        return ans;
    }
};