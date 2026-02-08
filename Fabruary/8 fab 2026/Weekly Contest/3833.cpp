class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1 ) return 0;
        int c = 0;
        double s = 0;
        for(int i = n-1 ; i >=0;i--){
            int v = nums[i];
            if(i < n-1){
                int k = n-i-1;
                if((double)v > (s/k)){
                    c++;
                }
            }
            s += v;
        }
        return c;
    }
};