class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, int> mp;

        for (int num : arr) {
            mp[num] = __builtin_popcount(num);
        }

        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if (mp[a] == mp[b]) return a < b;
            return mp[a] < mp[b];
        });

        return arr;
    }
};