class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            vector<int>& v = mp[nums[q]];

            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int k = v.size();
            int pos = lower_bound(v.begin(), v.end(), q) - v.begin();

            int next = v[(pos + 1) % k];
            int prev = v[(pos - 1 + k) % k];
            int d1 = abs(next - q);
            int d2 = abs(prev - q);

            d1 = min(d1, n - d1);
            d2 = min(d2, n - d2);

            ans.push_back(min(d1, d2));
        }

        return ans;
    }
};