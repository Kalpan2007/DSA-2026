class Solution {
public:
    using ll = long long;

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums2[i], nums1[i]});
        }

        sort(v.rbegin(), v.rend());
        priority_queue<int, vector<int>, greater<int>> pq;

        ll sum = 0, ans = 0;

        for (auto &p : v) {
            sum += p.second;
            pq.push(p.second);

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                ans = max(ans, sum * (ll)p.first);
            }
        }

        return ans;
    }
};