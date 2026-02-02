class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k==0) return;
        vector<int> temp(nums.size());
        for(int i=0;i<nums.size();i++){
            temp[(i+k) % nums.size()] = nums[i];
        }
        nums = temp;
        return ;
    }
};