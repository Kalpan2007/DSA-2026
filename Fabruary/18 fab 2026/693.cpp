class Solution {
public:
    string convert_binary(int n) {
        string binary_n = "";
        while (n > 0) {
            int remainder = n % 2;
            binary_n += to_string(remainder);
            n /= 2;
        }
        reverse(binary_n.begin(), binary_n.end());
        return binary_n;
    }

    bool hasAlternatingBits(int n) {
        string binary_n = convert_binary(n);
        for (int i = 0; i < binary_n.size(); i++) {
            cout << binary_n[i] << endl;
            if (binary_n[i] == binary_n[i + 1]) {
                return false;
            }
        }
        return true;
    }
};