class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string search_word) {
        vector<vector<string>> ans;
        string prefix = "";

        for (char ch : search_word) {
            prefix += ch;
            vector<string> temp;
            for (string product : products) {
                if (product.size() >= prefix.size() &&
                    product.substr(0, prefix.size()) == prefix) {
                    temp.push_back(product);
                }
            }
            sort(temp.begin(), temp.end());

            vector<string> top3;
            for (int i = 0; i < temp.size() && i < 3; i++) {
                top3.push_back(temp[i]);
            }

            ans.push_back(top3);
        }

        return ans;
    }
};