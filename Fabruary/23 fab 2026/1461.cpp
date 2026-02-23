class Solution {
public:
    void k_strings(int k, string curr, unordered_map<string, int>& mp) {
        if (curr.size() == k) {
            mp[curr] = 1;
            return;
        }

        k_strings(k, curr + '0', mp);
        k_strings(k, curr + '1', mp);
    }

    bool hasAllCodes(string s, int k) {
        int n = s.size();

        if ((1LL << k) > (long long)(n - k + 1)) {
            return false;
        }

        unordered_map<string, int> mp;

        if (k == 1) {
            mp["0"] = 1;
            mp["1"] = 1;
        } else {
            k_strings(k, "", mp);
        }

        for (int i = 0; i + k <= n; i++) {
            string sub = s.substr(i, k);
            if (mp.count(sub)) {
                mp.erase(sub);
            }
        }

        return mp.empty();
    }
};