class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans = -1;
        int min_cap = INT_MAX;
        for(int i = 0 ;i < capacity.size();i++){
            
          
            if(itemSize <= capacity[i]){
                if(capacity[i] < min_cap){
                    min_cap = capacity[i];
                    ans = i;
                }
            }
        }
        return ans;
    }
};