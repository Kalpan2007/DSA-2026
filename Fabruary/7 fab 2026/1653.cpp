class Solution {
public:
    int minimumDeletions(string s) {
        if (s.size() == 1)
            return 0;
        cout << s.size() << endl;
        int totalA = 0;
        for (char c : s) {
            if (c == 'a')
                totalA++;
        }
        if (totalA == 0 || totalA == s.size())
            return 0;
        int a_right = totalA;
        int b_left = 0;
        int ans = min(totalA, (int)s.size() - totalA);
        cout << ans;
        for (char c : s) {
            if (c == 'a')
                a_right--;
            else
                b_left++;

            ans = min(ans, b_left + a_right);
        }

        return ans;
    }
};
