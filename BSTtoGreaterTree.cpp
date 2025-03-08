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
    int sum = 0;
    int N = 1e5;
    map<int,int> vis;
    void dfs(TreeNode* root, int flag) {
        if (root) {
            if (root->right == NULL && flag != 1) {
                sum += root->val;
                cout << root->val << " " << sum << endl;
                mp[root->val] = sum;
                vis[root->val] = 1;
            }
            dfs(root->right, flag = 1);
            if (vis[root->val] == 0){
                sum += root->val;
                mp[root->val] = sum;
                vis[root->val] = 1;
            }
            cout << root->val << " " << sum << endl;
            dfs(root->left, flag = 0);
            //sum -= root->val;
            
            
        }
    }
    void chng(TreeNode* root) {
        if (root) {
            root->val = mp[root->val];
            chng(root->left);
            chng(root->right);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root, 1);
        chng(root);
        // for (auto x : mp) {
        //     cout << x.first << " " << x.second << endl;
        // }
        return root;
    }
};