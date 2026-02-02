class Solution {
public:
    typedef pair<long long, long long> p;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        set<p> kmin;
        set<p> remains;

        long long sum = 0;
        int i = 1;
        while (i - dist < 1) {
            kmin.insert({nums[i], i});
            sum += nums[i];
            if (kmin.size() > k - 1) {
                p temp = *kmin.rbegin();
                sum -= temp.first;
                remains.insert(temp);
                kmin.erase(temp);
            }
            i++;
        }

        long long result = LONG_MAX;
        while (i < n) {
            kmin.insert({nums[i], i});
            sum += nums[i];
            if (kmin.size() > k - 1) {
                p temp = *kmin.rbegin();
                sum -= temp.first;
                remains.insert(temp);
                kmin.erase(temp);
            }
            result = min(result, sum);

            p remove = {nums[i - dist], i - dist};
            if (kmin.count(remove)) {
                kmin.erase(remove);
                sum -= remove.first;
                if (!remains.empty()) {
                    p temp = *remains.begin();
                    kmin.insert(temp);
                    sum += temp.first;
                    remains.erase(temp);
                }
            } else {
                remains.erase(remove);
            }
            i++;
        }
        return nums[0] + result;
    }
};