class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 1;
        int maxel = nums[0];
        int minel = nums[0];
        int i = 0;
        int j = 0;
        while (j < n) {
            minel = nums[i];
            maxel = nums[j];
            while(i<j && maxel > (long long)minel * k){
                i++;
                minel = nums[i];
            }
            l = max(l , j-i+1);
            j++;
        }
        return n-l;
    }
};