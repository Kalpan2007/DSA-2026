class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& g) {
        int r = g.size(), c = g[0].size();
        
        vector<int> _d(c, 0), _x(c, 0);
        int ans = 0;

        for (int _i = 0; _i < r; _i++) {
            int _rd = 0, _rx = 0;

            for (int _j = 0; _j < c; _j++) {
                if (g[_i][_j] == 'X') {
                    _rd++;
                    _rx = 1;
                } 
                else if (g[_i][_j] == 'Y') {
                    _rd--;
                }

                _d[_j] += _rd;
                _x[_j] |= _rx;

                if (_x[_j] && _d[_j] == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};