class Solution {
public:
    void all_combination(vector<int>& nums, int idx, int target,
                         vector<vector<int>>& ans, vector<int>& combination) {

        if (target == 0) {
            ans.push_back(combination);
            return;
        }
        if (idx >= nums.size() || target < 0) {
            return;
        }

        combination.push_back(nums[idx]);
        all_combination(nums, idx, target - nums[idx], ans, combination);

        combination.pop_back();

        all_combination(nums, idx + 1, target, ans, combination);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int t) {
        vector<vector<int>> ans;
        vector<int> combination;

        all_combination(nums, 0, t, ans, combination);
        return ans;
    }
};