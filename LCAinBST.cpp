/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root) {
            int p1 = p->val;
            int q1 = q->val;
            int r = root->val;
            if (p1 < r && q1 > r) {
                ans = root;
                return;
            }
            if (q1 < r && p1 > r) {
                ans = root;
                return;
            }
            if (p1 == r || q1 == r) {
                ans = root;
                return;
            }
            if (p1 < r) {
                dfs(root->left, p, q);
            }
            else {
                dfs(root->right, p, q);
            }
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans;
    }
};