class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n == 0) return ans;

        int start = nums[0];
        int end = nums[0];

        for(int i = 0 ; i < n ; i++){            
            if(i+1 < n && nums[i] + 1 == nums[i+1]){
                end = nums[i+1];
            }
            else{
                if(start == end){
                    ans.push_back(to_string(start));
                }
                else{
                    ans.push_back(to_string(start) + "->" + to_string(end));
                }

                if(i+1 < n){
                    start = nums[i+1];
                    end = nums[i+1];
                }
            }
        }
        return ans;
    }
};