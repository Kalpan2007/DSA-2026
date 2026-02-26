/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* ans) {
        if (!root) return NULL;

        if (!root->left && !root->right) return root;

        TreeNode* leftTail = dfs(root->left, ans);
        TreeNode* rightTail = dfs(root->right, ans);

        if (root->left) {
            if (leftTail) {
                leftTail->right = root->right;
            }
            root->right = root->left;
            root->left = NULL;
        }

        if (rightTail) return rightTail;
        if (leftTail) return leftTail;
        return root;
    }

    void flatten(TreeNode* root) {
        dfs(root, root);
    }
};