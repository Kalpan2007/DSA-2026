class Solution {
public:
    string convert_binary(int n) {
        if (n == 0)
            return "0";

        string bs = "";
        while (n > 0) {
            int remainder = n % 2;
            bs += std::to_string(remainder);
            n /= 2;
        }
        reverse(bs.begin(), bs.end());
        return bs;
    }

    int binaryGap(int n) {
        string bs = convert_binary(n);
        int temp = -1;
        int ans = 0;
        for (int i = 0; i < bs.size(); i++) {
            if (bs[i] == '1') {
                if (temp != -1) {
                    ans = max(ans, i - temp);
                }
                temp = i;
            }
        }
        return ans;
    }
};