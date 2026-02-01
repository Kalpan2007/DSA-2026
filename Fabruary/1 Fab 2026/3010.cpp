class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int f = nums[0];
        sort(nums.begin() + 1, nums.end());
        return f + nums[1] + nums[2];
    }
};