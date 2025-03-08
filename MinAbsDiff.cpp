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
    int ans = 1e9;
    int curr = -1;
    void dfs(TreeNode* root) {
        if (root) {
            dfs(root->left);
            if (curr == -1) curr = root->val;
            else {
                ans = min(ans,abs(root->val - curr));
                curr = root->val;
            }
            dfs(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }
};