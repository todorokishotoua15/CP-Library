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
    TreeNode* root = new TreeNode(-1e9);
    
    vector<int> v;
    void build(int l, int r, TreeNode* root) {
        if (l > r || root == NULL) return;
        if (l == r) {
            root->val = v[l];
            return;
        }
        int mid = (l+r)/2;
        root->val = v[mid];
        if (l <= mid - 1){
            TreeNode* left = new TreeNode(-1e9);
            root->left = left;
        }
        if (r >= mid + 1){
            TreeNode* right = new TreeNode(-1e9);
            root->right = right;
        }
        
        build(l, mid-1, root->left);
        build(mid+1, r, root->right);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        for (auto x : nums)v.push_back(x);
        build(0,v.size()-1,root);
        return root;
    }
};