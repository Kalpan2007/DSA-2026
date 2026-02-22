class Solution {
public:
    map<tuple<int, int, int, int>, long long> memo;
    int target_2 = 0;
    int target_3 = 0;
    int target_5 = 0;

    void extra_factors(long long val, int& p2, int& p3, int& p5) {
        p2 = 0;
        p3 = 0;
        p5 = 0;

        while (val % 2 == 0) {
            p2++;
            val /= 2;
        }
        while (val % 3 == 0) {
            p3++;
            val /= 3;
        }
        while (val % 5 == 0) {
            p5++;
            val /= 5;
        }
    }
    long long findways(vector<int>& nums, int id, int a, int b, int c) {

        if(abs(a) > 40 || abs(b) > 40 || abs(c) > 40) return 0;
        if (id == nums.size()) {
            return (a == target_2 && b == target_3 && c == target_5) ? 1 : 0;
        }

        auto key = make_tuple(id, a, b, c);

        auto it = memo.find(key);
        if(it != memo.end()){
            return it->second;
        }

        int n2, n3, n5;
        extra_factors(nums[id], n2, n3, n5);

        long long ways = 0;
        ways = (ways + findways(nums, id + 1, a + n2, b + n3, c + n5)) ;
        ways = (ways + findways(nums, id + 1, a - n2, b - n3, c - n5)) ;
        ways = (ways + findways(nums, id + 1, a, b, c)) ;

        return memo[key] = ways;
    }
    int countSequences(vector<int>& nums, long long k) {
        long long tk = k;
        target_2 = 0;
        target_3 = 0;
        target_5 = 0;
        long long temp = k;
        auto r = nums;

        while (temp % 2 == 0) {
            target_2++;
            temp /= 2;
        }
        while (temp % 3 == 0) {
            target_3++;
            temp /= 3;
        }
        while (temp % 5 == 0) {
            target_5++;
            temp /= 5;
        }
        if (temp != 1)
            return 0;
        memo.clear();
        return (int)findways(nums, 0, 0, 0, 0);
    }
};