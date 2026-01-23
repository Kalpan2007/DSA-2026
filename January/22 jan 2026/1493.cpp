class Solution {
public:
    int n;
    int findmax(vector<int>& nums, int si) {
        int cl = 0;
        int ml = 0;
        for (int i = 0; i < n; i++) {
            if (i == si)
                continue;
            if (nums[i] == 1) {
                cl++;
                ml = max(ml, cl);

            } else {
                cl = 0;
            }
        }
        return ml;
    }

    int longestSubarray(vector<int>& nums) {
        n = nums.size();
        int countzero = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                countzero++;
                result = max(result, findmax(nums, i));
            }
        }
        if(countzero==0)return n-1;
        return result;
    }
};