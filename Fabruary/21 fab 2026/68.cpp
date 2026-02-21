class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0, n = words.size();

        while (i < n) {
            int j = i;
            int lineLen = 0;

            
            while (j < n && lineLen + words[j].size() + (j - i) <= maxWidth) {
                lineLen += words[j].size();
                j++;
            }

            vector<string> lineWords(words.begin() + i, words.begin() + j);
            int spaces = maxWidth - lineLen;
            string line;

            
            if (j == n || lineWords.size() == 1) {
                for (int k = 0; k < lineWords.size(); k++) {
                    if (k > 0) line += " ";
                    line += lineWords[k];
                }
                line += string(maxWidth - line.size(), ' ');
            } 
            else {
                int gaps = lineWords.size() - 1;
                int even_space = spaces / gaps;
                int extra = spaces % gaps;

                for (int k = 0; k < gaps; k++) {
                    line += lineWords[k];
                    line += string(even_space + (k < extra ? 1 : 0), ' ');
                }
                line += lineWords.back();
            }

            res.push_back(line);
            i = j;
        }

        return res;
    }
};