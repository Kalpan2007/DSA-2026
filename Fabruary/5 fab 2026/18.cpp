class Solution {
public:
    vector<vector<int>> result;

    void twosum(vector<int>& nums, long long target, int i, int j, int a, int b) {
        while (i < j) {
            long long sum = nums[i] + nums[j];
            if (sum > target) {
                j--;
            } else if (sum < target) {
                i++;
            } else {
                result.push_back({a, b, nums[i], nums[j]});

                while (i < j && nums[i] == nums[i + 1]) i++;
                while (i < j && nums[j] == nums[j - 1]) j--;

                i++;
                j--;
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        result.clear();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            cout << i << endl;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                  cout << j <<endl;
                long long newtarget = (long long)target - nums[i] - nums[j];
                cout << newtarget << endl;
                twosum(nums, newtarget, j + 1, n - 1, nums[i], nums[j]);
            }
        }
        return result;
    }
};
