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

void dfs(TreeNode* root , int max_val,int& ans){
    if(!root) return ;
    if(root->val >= max_val){
        ans++;
        max_val = max(root->val , max_val);
    }
    dfs(root->left , max_val , ans);
    dfs(root->right, max_val , ans);
    return;
}
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int ans = 1;
        dfs(root->left , root->val , ans);
        dfs(root->right , root->val , ans);
        return ans;
    }
};