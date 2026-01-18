class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int vl = n;
        unordered_set<int> ms;
        for(int i = 0 ;i < n ; i++){
            if(nums[i] != target[i]){
                ms.insert(nums[i]);
            }
        }
        return ms.size();
    }
};