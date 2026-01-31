class Solution {
public:
    bool checkIfExist(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = 0 ; j <nums.size();j++){
                if(nums[i]==nums[j]*2 && i!=j){
                    return true;
                }
            }
        }
        return false;
    }
};