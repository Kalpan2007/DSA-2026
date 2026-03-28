class Solution {
public:
    int count = 0;

    string helper(int n, int k, string &s) {

        if (s.length() == n) {
            count++;

            if (count == k)
                return s;

            return "";
        }

        if (s.empty() || s.back() != 'a') {
            s.push_back('a');
            string res = helper(n, k, s);
            if (res != "") return res;
            s.pop_back();
        }

        if (s.empty() || s.back() != 'b') {
            s.push_back('b');
            string res = helper(n, k, s);
            if (res != "") return res;
            s.pop_back();
        }

        if (s.empty() || s.back() != 'c') {
            s.push_back('c');
            string res = helper(n, k, s);
            if (res != "") return res;
            s.pop_back();
        }

        return "";
    }

    string getHappyString(int n, int k) {

        int size = 3 * pow(2, n - 1);

        if (k > size) return "";

        string s = "";
        return helper(n, k, s);
    }
};