class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        long long total =0;
        for(int x : nums) total += x;

        vector<long long> right_prod(n , 1);
        long long curr = 1;

        for(int i = n-2 ; i >=0 ; i--){
            if(nums[i+1] !=0 && curr > (total +1)/nums[i+1]){
                curr = total +1;
            }else{
                curr *= (long long)nums[i+1];
            }
            right_prod[i] = curr;
        }
        long long left=0;
        for(int i = 0;i < n;i++){
            if(left == right_prod[i]){
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};