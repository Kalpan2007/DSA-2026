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
    int ans;

    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftMaxDownwardPath = dfs(root->left);
        int rightMaxDownwardPath = dfs(root->right);
        int All_Sum = leftMaxDownwardPath + rightMaxDownwardPath + root->val;

        int Right_or_Left = max(leftMaxDownwardPath, rightMaxDownwardPath) + root->val;

        int node_only_sum = root->val;

        ans = max({ans, All_Sum, Right_or_Left, node_only_sum});
        return max(Right_or_Left, node_only_sum);
    }

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};