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
    void dfs(TreeNode* node, bool left, int length, int& ans) {
        if(!node) return;
        ans = max(ans , length);
        if(left){
            dfs(node->left, false , length+1 , ans);
            dfs(node->right , true , 1 ,ans);
        }else{
            dfs(node->right , true , length+1 ,ans);
            dfs(node->left , false , 1 , ans);
        }
    }
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        dfs(root, true, 0, ans);
        dfs(root, false, 0, ans);
        return ans;
    }
};