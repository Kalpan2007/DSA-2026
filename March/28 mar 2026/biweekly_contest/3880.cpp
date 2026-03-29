class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        bool f = false;
        int d = INT_MAX;

        for(int i = 0 ; i < nums.size();i++){
            for(int j = 0 ; j < nums.size();j++){
                if(nums[i]==1 && nums[j]==2){
                    d = min(d  , abs(i-j));
                    f = true;
                }
            }
        }
        return f ? d : -1;
    }
};