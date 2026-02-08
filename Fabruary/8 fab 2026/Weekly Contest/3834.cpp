class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res;
        for(int i = 0 ; i < n ;i++){
            long long x = nums[i];
            while(!res.empty() && res.back()==x){
                x += res.back();
                res.pop_back();
            }
            res.push_back(x);
        }
        return res;
    }
};  