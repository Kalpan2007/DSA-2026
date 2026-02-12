class Solution {
public:
    int longestBalanced(string s) {
        int ans = 1;

        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> mp;

            for (int j = i; j < s.size(); j++) {
                mp[s[j]]++;

                int freq = -1;
                bool ok = true;

                for (auto& it : mp) {
                    if (freq == -1)
                        freq = it.second;
                    else if (freq != it.second) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
