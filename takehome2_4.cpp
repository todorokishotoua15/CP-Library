#include <bits/stdc++.h>
 
using namespace std;

template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
#define rep(i,a,b) for(int i = a; i < b; i ++)
#define ill long long int
#define ll long long
#define nl "\n"
#define el endl
#define pb push_back


 
const int N = 3e5 + 2;
const ll neg_inf = -2e7 + 2;
const ll inf = 1e18 + 1;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

map<pair<TreeNode*,int>, int> mp;
void dfs(TreeNode* node) {
    if (node) {
        dfs(node->left);
        dfs(node->right);
        
        if (node->left == NULL && node->right == NULL) {
            int v = node->val;
            //cout << v << endl;
            mp[{node,0}] = -1e9;
            mp[{node,1}] = v;
            mp[{node,2}] = -1e9;
            mp[{node,3}] = v;
        }
        else {
            int v = node->val;
            mp[{node,0}] = -1e9;
            mp[{node,1}] = -1e9;
            mp[{node,2}] = -1e9;
            mp[{node,3}] = -1e9;
            //cout << v << endl;
            if (node->left) {
                for (int i = 0; i < 4; i++) {
                    if (i != 1)mp[{node,0}] = max(mp[{node,0}],mp[{node->left,i}] + v);
                }
            }
            if (node->right) {
                for (int i = 0; i < 4; i++) {
                    if (i != 1)mp[{node,2}] = max(mp[{node,2}],mp[{node->right,i}] + v);
                }
            }
            if (node->left && node->right) {
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        if (i == 1 || j == 1) continue;
                        mp[{node,1}] = max(mp[{node,1}],mp[{node->right,i}] + mp[{node->left,j}] + v);
                    }
                }
            }
            mp[{node,3}] = v;
        }
    }
}

int maxPathSum(TreeNode* root) {
    dfs(root);
    int ans = -1e9;
    for (auto x : mp) {
        //cout << x.first.first << " " << x.first.second << " " << x.second << endl;
        ans = max(ans,x.second);
    }
    return ans;
}