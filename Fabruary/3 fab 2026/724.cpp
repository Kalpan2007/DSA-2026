class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        int lsum =0;
        for(int i =0;i<n;i++){
            left[i] = lsum;
            lsum += nums[i]; 
        }
        int rsum = 0;
        for(int i = n-1 ; i>=0;i--){
            right[i] = rsum;
            rsum += nums[i];
        }
        for(int i = 0;i<n ; i++){
            if(right[i]==left[i]) return i;
        }
        return -1;
    }
};