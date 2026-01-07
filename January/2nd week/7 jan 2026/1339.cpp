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
    long S = 0;
    long mp = 1;

    int totalsum(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = totalsum(root->left);
        int right = totalsum(root->right);
        int sum = root->val + left + right;
        return sum;
    }

    int find(TreeNode* root){
        if(root==NULL) return 0;
        int left = find(root->left);
        int right = find(root->right);
        long subtree = root->val + left + right;
        long remain = S - subtree;
        mp = max(mp , remain * subtree);
        return subtree;
    }

    int maxProduct(TreeNode* root) {
        if (root == NULL)
            return 0;
        S = totalsum(root);
        mp = 1;
        find(root);
        return mp % 1000000007;
    }
};