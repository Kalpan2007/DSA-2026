class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int l = 1;
        unordered_set<int> s;
        for(int i = 0; i < nums.size() ; i++){
            s.insert(nums[i]);
        }
        for(auto it : s){
            if(s.find(it-1)==s.end()){
                int c = 1;
                int x = it;
                while(s.find(x+1) != s.end()){
                    x++;
                    c++;
                }
                l = max(l , c);
            }
        }
        return l;
    }
};