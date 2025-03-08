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
    int ans = -1;
    int k1 = -1;
    int order = 0;
    void dfs(TreeNode* root) {
        if (root) {
            dfs(root->left);
            order+=1;
            if (order == k1) ans = root->val;
            dfs(root->right);
            //cout << root->val << endl;
            
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        k1 = k;
        dfs(root);
        return ans;
    }
};