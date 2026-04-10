class Solution {
public:
   long long mod=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        for(int i=0;i<n;i++){
             int l=queries[i][0],r=queries[i][1],k=queries[i][2],v=queries[i][3];
             while(l<=r){
                nums[l]=(1LL *nums[l]*v)% mod;
                l=l+k;
             }
        }
        long long s=0;
        for(int i=0;i<nums.size();i++){
            s=s^nums[i];
        }
        return s;
    }
};