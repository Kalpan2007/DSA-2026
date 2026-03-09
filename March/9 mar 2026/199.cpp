/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
// we do levalorder traversal and first root->val push after goes right and when right end we just go left leval till we end on right
    void preorder(TreeNode* root, int leval, vector<int>& ans) {
        if (root == NULL)
            return;
        if (ans.size() < leval) {
            ans.push_back(root->val);
        }
        preorder(root->right, leval + 1, ans);
        preorder(root->left, leval + 1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preorder(root, 1, ans);
        return ans;
    }
};