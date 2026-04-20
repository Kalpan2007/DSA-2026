class Solution {
public:
    int maxDistance(vector<int>& colors) {
    int n = colors.size();

    unordered_map<int, pair<int, int>> mp;

    for (int i = 0; i < n; i++) {
        if (mp.find(colors[i]) == mp.end()) {
            mp[colors[i]] = {i, i};
        } else {
            mp[colors[i]].second = i;
        }
    }

    int ans = 0;

    for (auto &it : mp) {
        int first = it.second.first;
        int last = it.second.second;

        if (colors[0] != it.first) {
            ans = max(ans, last - 0);
        }

        if (colors[n - 1] != it.first) {
            ans = max(ans, (n - 1) - first);
        }
    }

    return ans;
}
};