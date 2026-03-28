class Solution {
public:
    using ll = long long;
    bool can(ll t, vector<int>& w, int h) {
        ll total = 0;

        for (int &time : w) {
            ll k = (ll)(sqrt(2.0 * t / time + 0.25) - 0.5);
            total += k;

            if (total >= h) return true;
        }

        return total >= h;
    }

    long long minNumberOfSeconds(int h, vector<int>& w) {
        int slow = *max_element(w.begin(), w.end());

        ll l = 1;
        ll r = (ll)slow * h * (h + 1) / 2;
        ll ans = r;

        while (l <= r) {
            ll mid = l + (r - l) / 2;

            if (can(mid, w, h)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};