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
    int maxLevelSum(TreeNode* root) {
        int msum = INT_MIN;
        int ans = 0;

        queue<TreeNode*> que;
        que.push(root);

        int current = 1;

        while(!que.empty()){
            int n = que.size();
            int sum = 0;
            while(n--){
                TreeNode* temp = que.front();
                que.pop(); 
                sum += temp->val;
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            if(sum > msum){
                msum = sum;
                ans = current;
            }
            current++;
        }
        return ans;
    }
};