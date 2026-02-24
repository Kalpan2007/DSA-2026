class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k <= 0 || n <= 1) return false;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= i + k && j < n; j++) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};