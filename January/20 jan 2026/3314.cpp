class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0;i<n;i++){
            bool f = false;
            for(int j = 0;j<nums[i];j++){
                if((j | j+1 ) == nums[i]){
                     ans.push_back(j);
                     f = true;
                     break;
                }
               
            }
             if(f==false) ans.push_back(-1);
        }
        return ans;
    }
};