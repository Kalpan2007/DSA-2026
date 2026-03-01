class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        for(int i =0;i<n;){
            int current_x = nums[i];
            int count_x = 0;
            int temp_i = i;

            while(temp_i < n && nums[temp_i] == current_x){
                count_x++;
                temp_i++;
            }

            for(int j = temp_i ; j< n; ){
                int current_y = nums[j];
                int count_y = 0;
                int temp_j = j;

                while(temp_j < n && nums[temp_j]==current_y){
                    count_y++;
                    temp_j++;
                }

                if(count_x != count_y){
                    return {current_x, current_y};
                }
                j = temp_j;
            }
            i = temp_i;
        }
        return {-1 ,-1};
    }
};