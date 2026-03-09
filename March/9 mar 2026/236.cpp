/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* target = nullptr;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return false;

        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        
        if (left + right + (root == q) + (root == p) == 2)
            target = root;

        if (left + right + (root == q) + (root == p) == 1)
            return true;

        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return target;
    }   
};