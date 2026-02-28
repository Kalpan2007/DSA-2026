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
    unordered_map<int, int> pos_map;
    int post_idx;

    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder,
                  int in_left, int in_right) {
        if (in_left > in_right) return nullptr;

        int root_val = postorder[post_idx--];
        TreeNode* root = new TreeNode(root_val);

        int mid = pos_map[root_val];

        root->right = dfs(inorder, postorder, mid + 1, in_right);
        root->left  = dfs(inorder, postorder, in_left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        post_idx = n - 1;

        for (int i = 0; i < n; i++)
            pos_map[inorder[i]] = i;

        return dfs(inorder, postorder, 0, n - 1);
    }
};