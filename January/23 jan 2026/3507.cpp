class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;

        while(!is_sorted(nums.begin(), nums.end())) {
            int sum = INT_MAX;
            int index = -1;

            for (int j = 0; j + 1 < nums.size(); j++) {
                if (nums[j] + nums[j + 1] < sum) {
                    sum = nums[j] + nums[j + 1];
                    index = j;
                }
            }

            nums[index] = sum;
            nums.erase(nums.begin() + index + 1);
            ans++;
        }
        return ans;
    }
};
