class Solution {
public:
    int solve(vector<int>& cost, int idx) {
        if(idx >= cost.size())
            return 0; //when you reach top, you don't have to pay anything

        int move_one = cost[idx] + solve(cost, idx+1);
        int move_two = cost[idx] + solve(cost, idx+2);
        
        return min(move_one, move_two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(solve(cost, 0), solve(cost, 1));
    }
};
