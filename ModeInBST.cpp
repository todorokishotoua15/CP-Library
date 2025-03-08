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
    map<int,int> mp;
    void dfs(TreeNode* root) {
        if (root) {
            mp[root->val]++;
            dfs(root->left);
            dfs(root->right);
        }
    }
    vector<int> findMode(TreeNode* root) {
        int ans = -1;
        int freq = 0;
        dfs(root);
        for (auto x : mp) {
            if (ans == -1) {
                ans = x.first;
                freq = x.second;
            }
            else if (x.second > freq) {
                freq = x.second;
                ans = x.first;
            }
        }
        vector<int> v ;
        
        for (auto x : mp) {
            if (x.second == freq) v.push_back(x.first);
        }
        return v;
    }
};