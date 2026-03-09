class Solution {
public:
    int M = 1e9 + 7;
    int t[201][201][2];

    int solve(int one_left, int zero_left, bool last_one, int limit) {
        if(one_left == 0 && zero_left == 0) {
            return 1;
        }

        if(t[one_left][zero_left][last_one] != -1) {
            return t[one_left][zero_left][last_one];
        }


        int result = 0;

        if(last_one == true) { 
            for(int len = 1; len <= min(zero_left, limit); len++) {
                result = (result + solve(one_left, zero_left - len, false, limit)) % M;
            }
        } else { 
            for(int len = 1; len <= min(one_left, limit); len++) {
                result = (result + solve(one_left - len, zero_left, true, limit)) % M;
            }
        }

        return t[one_left][zero_left][last_one] = result;

    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));
        int swo = solve(one, zero, false, limit);
        int swz = solve(one, zero, true, limit);

        return (swo + swz) % M;

    }
};