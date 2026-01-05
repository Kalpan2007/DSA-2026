class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int sum = 0;
            int count = 0;

            for (int j = 1; j * j <= n; j++) {
                if (n % j == 0) {
                    sum += j;
                    count++;
                    if (j != n / j) {
                        sum += n / j;
                        count++;
                    }
                    if (count > 4) break;
                }
            }

            if (count == 4) {
                ans += sum;
            }
        }

        return ans;
    }
};
