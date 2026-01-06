class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        vector<int> runs;

        if (operations.empty()){
            return 0;
        }

        for (const string& i : operations) {
            if (i == "+") {
                int temp = runs[runs.size() - 1] + runs[runs.size() - 2];
                runs.push_back(temp);
            } else if (i == "D") {
                int temp = runs.back() * 2;
                runs.push_back(temp);
            } else if (i == "C") {
                runs.pop_back();
            } else {
                runs.push_back(stoi(i));
            }
        }

        for (int j : runs) {
            sum += j;
        }
        return sum;
    }
};