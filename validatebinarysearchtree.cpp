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
    int flag = 1;
    long long curr = -1e12;
    
    void inorder(TreeNode* root) {
        if (root) {
            inorder(root->left);
            //cout << curr << " " << root->val << endl;
            if (curr == -1e12) curr = root->val;
            else if (root->val <= curr) flag = 0;
            else curr = root->val;
            
            inorder(root->right);
        }    
    }
    
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return flag;
    }
};