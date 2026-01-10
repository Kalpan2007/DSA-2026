class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> vec;
        int n = chars.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            char current = chars[i];
            int count = 1;

            while(i + 1 < n && chars[i] == chars[i + 1]) {
                count++;
                i++;
            }

            vec.push_back(current);
            ans++;

            if(count > 1) {
                string cnt = to_string(count);
                for(char c : cnt) {
                    vec.push_back(c);
                }
                ans += cnt.size();
            }
        }

        chars = vec;
        return ans;
    }
};
