class Solution {
public:
 int reverse(int n) {
        int reversed = 0;
        while (n != 0) {
            reversed = reversed * 10 + (n % 10);
            n /= 10;
        }
        return reversed;
    }
    int mirrorDistance(int n) {
        return abs(reverse(n)-n);
    }
};