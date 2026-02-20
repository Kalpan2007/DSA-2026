class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> stores;

        int count = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;

            if (count == 0) {
                string in_string = s.substr(start + 1, i - start - 1);
                string recr_string = makeLargestSpecial(in_string);
                stores.push_back("1" + recr_string + "0");
                start = i + 1;
            }   
        }

        sort(stores.begin(), stores.end(), greater<string>());

        string ans = "";
        for (auto& b : stores) {
            ans += b;
        }

        return ans;
    }
};