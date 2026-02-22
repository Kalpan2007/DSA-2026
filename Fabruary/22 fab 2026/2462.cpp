class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> left_heap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> right_heap;

        int l = 0;
        int r = n - 1;

        for (int i = 0; i < candidates && l <= r; i++) {
            left_heap.push({costs[l], l});
            l++;
        }

        for (int i = 0; i < candidates && l <= r; i++) {
            right_heap.push({costs[r], r});
            r--;
        }
        
        long long ans = 0;
        while (k--) {
            pair<int, int> left_top = {INT_MAX, INT_MAX};
            pair<int, int> right_top = {INT_MAX, INT_MAX};

            if (!left_heap.empty())
                left_top = left_heap.top();
            if (!right_heap.empty())
                right_top = right_heap.top();

            if (left_top <= right_top) {
                ans += left_top.first;
                left_heap.pop();

                if (l <= r) {
                    left_heap.push({costs[l], l});
                    l++;
                }
            } else {
                ans += right_top.first;
                right_heap.pop();

                if (l <= r) {
                    right_heap.push({costs[r], r});
                    r--;
                }
            }
        }

        return ans;
    }
};