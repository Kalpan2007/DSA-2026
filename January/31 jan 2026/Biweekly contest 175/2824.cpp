class Solution {
public:
    int minimumK(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        int r = 200000;
        int a = r;

        while(l <=r){
            long long m =l + (r-l) / 2;
            long long c = 0;

            for(int i = 0;i<n;i++){
                c += (nums[i] + m - 1) / m;
            }
            if(c <= m*m){
                a = m;
                r = m -1;
            }else{
                l = m +1;
            }
        }
        return a;
    }
};