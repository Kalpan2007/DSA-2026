class Solution {
public:
    vector<string> readBinaryWatch(int to) {
        vector<string> ans;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (__builtin_popcount(i) + __builtin_popcount(j) == to) {
                    string h = to_string(i);
                    string m = (j < 10 ? "0" : "") + to_string(j);
                    ans.push_back(h + ':' + m);
                }
            }
        }
        return ans;
    }
};