class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        vector<int> s;
        int n = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] < 0) n++;
                s.push_back(matrix[i][j]);
            }
        }

        if (n % 2 == 0) {
            for (int i = 0; i < s.size(); i++) {
                sum += (long long)abs(s[i]);
            }
            return sum;
        } 
        else {
            int minAbs = INT_MAX;
            int index = -1;

            for (int i = 0; i < s.size(); i++) {
                if (abs(s[i]) < minAbs) {
                    minAbs = abs(s[i]);
                    index = i;   
                }
            }

          
            for (int i = 0; i < s.size(); i++) {
                if (i != index) {
                    sum += (long long)abs(s[i]);
                } else {
                    sum += (long long)(-abs(s[i]));
                }
            }
            return sum;
        }
    }
};
