class Solution {
public:
    int countPrimeSetBits(int left, int right) 
    {
        static const unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

        int ans = 0;
        for (int x = left; x <= right; ++x) 
        {
            int cnt = __builtin_popcount(x);
            if (primes.count(cnt)) 
            {
                ++ans;
            }
        }
        return ans;
    }
};