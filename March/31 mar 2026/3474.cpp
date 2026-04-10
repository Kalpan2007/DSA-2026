class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
    int total = n + m - 1;
    
    vector<char> word(total, 'a');
    vector<bool> locked(total, false);
    for (int i = 0; i < n; i++) {
        if (str1[i] == 'T') {
            for (int j = 0; j < m; j++) {
                int pos = i + j;
                if (locked[pos]) {
                    if (word[pos] != str2[j]) return ""; 
                } else {
                    word[pos] = str2[j];
                    locked[pos] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (str1[i] == 'F') {
            bool matches = true;
            for (int j = 0; j < m; j++) {
                if (word[i + j] != str2[j]) { matches = false; break; }
            }
            
            if (matches) {
                bool changed = false;
                for (int j = m - 1; j >= 0; j--) {
                    int pos = i + j;
                    if (!locked[pos] && str2[j] < 'z') {
                        word[pos] = str2[j] + 1;
                        changed = true;
                        break;
                    }
                }
                if (!changed) return "";
            }
        }
    }
    
    return string(word.begin(), word.end());
    }
};