#include <climits>

class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) {
        char c = l[0];
        int ans = INT_MAX;

        for (int i = 0; i < l.size(); i++) {
            int diff = l[i] - t;
            if (diff > 0 && diff < ans) {
                ans = diff;
                c = l[i];
            }
        }

       
        return (ans == INT_MAX) ? l[0] : c;
    }
};
