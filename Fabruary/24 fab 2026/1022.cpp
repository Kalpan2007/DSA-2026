/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 *     right(right) {}
 * };
 */
class Solution {
public:
    int binaryToDecimal(string n) {
        string num = n;
        int dec_value = 0;
        int base = 1;
        int len = num.length();

        for (int i = len - 1; i >= 0; i--) {
            if (num[i] == '1') {
                dec_value += base;
            }
            base = base * 2;
        }
        return dec_value;
    }

    int dfs(TreeNode* node, string path) {
        if (!node) return 0;

        path.push_back(node->val + '0');

        if (!node->left && !node->right) {
            return binaryToDecimal(path);
        }
        return dfs(node->left, path) + dfs(node->right, path);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, "");
    }
};