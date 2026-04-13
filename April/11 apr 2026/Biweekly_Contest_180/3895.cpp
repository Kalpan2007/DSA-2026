class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        for (int n : nums) {
            do {
                int last_digit = n % 10;
                if (last_digit == digit)
                    ans++;
                n /= 10;
            } while (n > 0);
        }

        return ans;
    }
};