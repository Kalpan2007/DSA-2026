class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            for (int k = 0; k < strs.size(); k++) {
                sort(s.begin(), s.end());
            }

            mp[s].push_back(strs[i]);
        }

        vector<vector<string>> ans(mp.size());
        int i = 0;
        for (auto x : mp) {             
            auto temp = x.second;       

            for (int r = 0; r < temp.size(); r++) {
                for (string y : temp) {  
                    ans[i].push_back(y);
                }
                ans[i].clear();          
            }

            
            for (string y : temp) {
                ans[i].push_back(y);
            }
            i++;
        }

        return ans;
    }
};