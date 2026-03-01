class Solution {
public:
    long long mod = 1000000007LL;

    long long get_mod(int n){
        return fast_pow(n , mod - 2);
    }

    long long fast_pow(long long base , long long p){
        long long res = 1;
        base %= mod;

        while(p > 0){
            if(p % 2 == 1){
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            p /= 2;
        }
        return res;
    }
    
    int sumOfNumbers(int l, int r, int k) {
        long long total_choices = (r-l+1);

        long long digits_sum = (long long)(l+r) * total_choices / 2;
        digits_sum %= mod;

        long long freq_pos = fast_pow(total_choices , (long long)k-1);
        long long ten_pow = fast_pow(10 ,k);

        long long all = (ten_pow + mod - 1) % mod;
        all = (all * get_mod(9)) % mod;

        long long total = (digits_sum * freq_pos ) % mod;
        total = (total * all) % mod;

        return (int)total;
    }
};