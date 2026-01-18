class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long mod = 1e9 + 7;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        unordered_set<long long> hashSet;
        for (int i = 0; i < hFences.size(); i++){
            for (int j = i + 1; j < hFences.size(); j++){
                hashSet.insert((long long)hFences[j] - hFences[i]);
            }
        }
        long long max_area = -1;
        for (int i = 0; i < vFences.size(); i++){
            for (int j = i + 1; j < vFences.size(); j++){
                long long d = ((long long)vFences[j] - vFences[i]);
                if (hashSet.count(d)){
                    max_area = max(max_area, d);
                }
            }
        }
        if (max_area == -1)
            return -1;

        return (int)((max_area * max_area) % mod);
    }
};class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long mod = 1e9 + 7;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        unordered_set<long long> hashSet;
        for (int i = 0; i < hFences.size(); i++){
            for (int j = i + 1; j < hFences.size(); j++){
                hashSet.insert((long long)hFences[j] - hFences[i]);
            }
        }
        long long max_area = -1;
        for (int i = 0; i < vFences.size(); i++){
            for (int j = i + 1; j < vFences.size(); j++){
                long long d = ((long long)vFences[j] - vFences[i]);
                if (hashSet.count(d)){
                    max_area = max(max_area, d);
                }
            }
        }
        if (max_area == -1)
            return -1;

        return (int)((max_area * max_area) % mod);
    }
};