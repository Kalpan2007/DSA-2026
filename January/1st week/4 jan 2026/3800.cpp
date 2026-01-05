class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost,
        int crossCost) {
        string q = s;
        long long counta = 0;
        long long countb = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '0' && t[i] == '1') {
                counta++;
            } else if (s[i] == '1' && t[i] == '0') {
                countb++;
            }
        }
        long long f = flipCost;
        long long sc = swapCost;
        long long cc = crossCost;
        long long costop = min(2 * f, sc);
        long long costsp = min(2 * f, cc + sc);
        long long pairs = min(counta, countb);
        long long remaining = abs(counta - countb);
        long long total = (pairs * costop) + ((remaining / 2) * costsp) +
                          ((remaining % 2) * f);
        return total;
    }
};