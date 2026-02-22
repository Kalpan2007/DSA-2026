class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int first_player = 0;
        int second_player = 0;
        bool active = true;

        for(int i = 0 ; i <nums.size() ; i++){
            int curret_points = nums[i];

            if(curret_points %2 !=0){
                active = !active;
            }

            if((i+1)%6==0){
                active = !active;
            }

            if(active){
                first_player += curret_points;
            }else{
                second_player += curret_points;
            }
        }
        return first_player - second_player;
    }
};