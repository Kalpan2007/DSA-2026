class Solution {
public:
    typedef long long ll;

    ll solve(int ri, int fi, vector<int>& robot, vector<int>& positions, vector<vector<ll>>& t) {
        if(ri >= robot.size()) {
            return 0; 
        }

        if(fi >= positions.size()) {
            return 1e12;
        }

        if(t[ri][fi] != -1) {
            return t[ri][fi];
        }

        ll take_current_factory = abs(robot[ri] - positions[fi]) + solve(ri+1, fi+1, robot, positions, t);
        ll skip = solve(ri, fi+1, robot, positions, t);

        return t[ri][fi] = min(take_current_factory, skip);
    }

    ll minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));

        int m = robot.size();
        
        vector<int> positions;
        for(int i = 0; i < factory.size(); i++) {
            int limit = factory[i][1];
            int pos   = factory[i][0];

            for(int j = 0; j < limit; j++) {
                positions.push_back(pos);
            }
        }
        int n = positions.size();
        vector<vector<ll>> t(m+1, vector<ll>(n+1, -1));
        return solve(0, 0, robot, positions, t);

    }
};
