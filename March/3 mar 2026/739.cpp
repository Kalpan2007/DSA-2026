class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);

        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;

            while (j < n) {
                if (temperatures[j] > temperatures[i]) {
                    answer[i] = j - i;
                    break;
                }
                if (answer[j] == 0) {
                    break;
                }
                j = j + answer[j];
            }
        }
        return answer;
    }
};