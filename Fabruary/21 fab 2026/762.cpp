class Solution {
public:
    bool is_prime(int n) {
        if (n <= 1)
            return false;

        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            int setbit = __builtin_popcount(i);
            bool check = is_prime(setbit);
            if (check)
                ans++;
        }
        return ans;
    }
};