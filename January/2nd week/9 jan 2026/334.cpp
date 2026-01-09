class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;   // i
        int second = INT_MAX;  // j

        for (int x : nums) {
            if (x <= first) {
                first = x;
            }
            else if (x <= second) {
                second = x;
            }
            else {
                return true;
            }
        }
        return false;
    }
};