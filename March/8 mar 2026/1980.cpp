class Solution {
public:
    string ans = "";

    void generate(int n, string curr, unordered_set<string>& st) {
        if(curr.size() == n) {
            if(st.find(curr) == st.end()) {
                ans = curr;
            }
            return;
        }

        if(ans != "") return;

        generate(n, curr + '0', st);
        generate(n, curr + '1', st);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        unordered_set<string> st(nums.begin(), nums.end());

        generate(n, "", st);

        return ans;
    }
};