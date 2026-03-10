class Solution {
public:
    int climbStairs(int n) {
    if (n == 1) return 1;
       int a = 1, ans = 2;
        for (int i = 3; i <= n; i++) {
            int c = a + ans;
             a=ans;
             ans=c;
    }
    return ans;
    }
};