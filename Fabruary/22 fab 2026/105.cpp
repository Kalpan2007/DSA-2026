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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;

        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);

        int id = 0;
        while (inorder[id] != rootVal) id++;

        vector<int> left_in(inorder.begin(), inorder.begin() + id);
        vector<int> right_in(inorder.begin() + id + 1, inorder.end());

        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + left_in.size());
        vector<int> rightPre(preorder.begin() + 1 + left_in.size(), preorder.end());

        root->left = buildTree(leftPre, left_in);
        root->right = buildTree(rightPre, right_in);

        return root;
    }
};