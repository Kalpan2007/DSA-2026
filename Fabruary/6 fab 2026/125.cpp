class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isalnum(c)) {
                a += tolower(c);
            }
        }
        cout << a << endl;
        int left = 0;
        int right = a.length() - 1;
        while (left < right) {
            if (a[left] != a[right]) {
                return false;  
            }
            left++;
            right--;
        }
      return true;  
    }
};