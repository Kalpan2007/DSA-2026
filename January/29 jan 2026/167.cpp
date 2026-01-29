class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
       int l = 0; 
       int r = num.size()-1; 

        while(l<=r){
            int sum= num[l]+ num[r];
            if(sum== target){
                return {l+1, r+1};
            }
            else if(sum < target){
                l++;
            }
            else{
                r--;
            }
        }
        return {};
    }
};