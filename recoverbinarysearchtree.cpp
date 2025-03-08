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
    vector<int> sorted;
    map<int,int> mp;
    void inorder(TreeNode* root) {
        if (root) {
            inorder(root->left);
            sorted.push_back(root->val);
            inorder(root->right);
        }
    }
    
    TreeNode* curr;
    void swapin(TreeNode* root) {
        if (root) {
            swapin(root->left);
            //cout << root->val << " " << mp[root->val] << endl;
            root->val = mp[root->val];
            swapin(root->right);
        }
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        vector<int> ss = sorted;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < ss.size(); i++) {
            //cout << ss[i] << " " << sorted[i] << endl;
            mp[ss[i]] = sorted[i];
        }
        swapin(root);
        
    }
};