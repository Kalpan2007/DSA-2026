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
    void inOrder(TreeNode* root, vector<int>& nodes) {
        if (!root)
            return;
        inOrder(root->left, nodes);
        nodes.push_back(root->val);
        inOrder(root->right, nodes);
    }

    TreeNode* solve(int l, int r, vector<int>& nodes) {
        if (l > r)
            return NULL;
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = solve(l, mid - 1, nodes);
        root->right = solve(mid + 1, r, nodes);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inOrder(root, nodes);
        int l = 0;
        int r = nodes.size() - 1;
        return solve(l, r, nodes);
    }
};