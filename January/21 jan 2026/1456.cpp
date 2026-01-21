class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int maxVowel = 0;
        int left = 0;
        int vowel = 0;

        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) vowel++;

            if ((i - left + 1) == k) {
                maxVowel = max(maxVowel, vowel);
                if (isVowel(s[left])) vowel--;
                left++;
            }
        }
        return maxVowel;
    }
};