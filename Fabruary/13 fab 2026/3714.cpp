class Solution {
public:
    int helper(string&s, int ch1, int ch2) {
        int n = s.length();
        unordered_map<int, int> dif_mp;
        int max_l = 0;
        int c1 = 0;
        int c2 = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] != ch1 && s[i] != ch2) {
                dif_mp.clear();
                c1 = 0;
                c2 = 0;
                continue;
            }

            if(s[i] == ch1)
                c1++;
            if(s[i] == ch2)
                c2++;

            if(c1 == c2) {
                max_l = max(max_l, c1+c2);
            }

            int diff = c1 - c2;
            if(dif_mp.count(diff)) {
                max_l = max(max_l, i - dif_mp[diff]);
            } else {
                dif_mp[diff] = i;
            }
        }
        
        return max_l;
    }

    int longestBalanced(string s) {
        int n    = s.length();
        int max_l = 0;

        // for one character like 'a' , 'b' and 'c
        int count = 1; 
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                count++;
            } else {
                max_l = max(max_l, count);
                count = 1;
            }
        }
        max_l = max(max_l, count);

        // make higher function for 2 character in pair 
        max_l = max(max_l, helper(s, 'a', 'b'));
        max_l = max(max_l, helper(s, 'a', 'c'));
        max_l = max(max_l, helper(s, 'b', 'c'));


        // for all 3 character 'abc' 
        int countA = 0;
        int countB = 0;
        int countC = 0;
        unordered_map<string, int> dif_mp;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a')
                countA++;
            if(s[i] == 'b')
                countB++;
            if(s[i] == 'c')
                countC++;

            if(countA == countB && countA == countC) {
                max_l = max(max_l, countA+countB+countC);
            }

            int diffAB = countA - countB;
            int diffAC = countA - countC;

            string key = to_string(diffAB) + "_" + to_string(diffAC); 

            if(dif_mp.count(key)) {
                max_l = max(max_l, i - dif_mp[key]);
            } else {
                dif_mp[key] = i;
            }
        }

        return max_l;

    }
};