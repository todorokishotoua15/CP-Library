#include<bits/stdc++.h>
using namespace std;


#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif

#define int int64_t
#define ll long long
#define nl "\n"
#define FOR(i,b,c) for (int i = b; i < c; i++)
 
const int32_t MAXN = 4e6+1;
const int32_t eps = 1e-6;
const int N = 2e5+5;
const int M = 27*3+2;
const int MOD = 998244353;

mt19937 rng(time(nullptr));

struct node {
    int value, priority;
    array<node*,2> child;
    int sub_size, sm, b,c, rev, flip, mul;
    node(int x);
};

int total_nodes(node *tree) {
    if (tree == NULL) return 0;
    return tree->sub_size;
}

void calc(node *tree) {
    if (tree == NULL) return;
    tree->sub_size = 1;
    tree->sm = (tree->value + (tree->prop*total_nodes(tree))%MOD)%MOD;
    // debug("prev",tree->value,tree->prop,tree->mul);
    // tree->sm = (tree->sm*tree->mul)%MOD;
    for (auto x : tree->child) {
        if (x == NULL) continue;
        tree->sub_size += x->sub_size;
        int childsum = (x->sm + (x->prop*total_nodes(x))%MOD)%MOD;
        // debug(childsum,x->mul,x->prop);
        tree->sm = (tree->sm + (childsum*x->mul)%MOD)%MOD;
    }
}

void push(node *tree) {
    if (tree == NULL) return;
    for (auto x : tree->child) {
        if (x == NULL) continue;
        x->prop = (x->prop+tree->prop)%MOD;
        x->flip += tree->flip;
        x->mul = (x->mul*tree->mul)%MOD;
    }
    tree->value = (tree->value+tree->prop)%MOD;
    tree->value = (tree->value*tree->mul)%MOD;
    if (tree->flip%2 == 0) tree->rev = 0;
    else tree->rev = 1;
    if (tree->rev == 1) {
        swap(tree->child[0],tree->child[1]);
        tree->rev = 0;
    }
    tree->flip = 0;
    tree->prop = 0;
    tree->mul = 1;
}

node::node(int x) {
    value = x;
    child = {NULL,NULL};
    sm = 0;
    b = 1;
    c = 0;
    rev = 0;
    flip = 0;
    mul = 1;
    calc(this);
    priority = rng();
}

array<node*,2> split(node *tree, int lef) {
    if (tree == NULL) return {NULL,NULL};
    push(tree);
    if (total_nodes(tree->child[0]) >= lef) {
        array<node*,2> res = split(tree->child[0],lef);
        tree->child[0] = res[1];
        calc(tree);
        return {res[0],tree};
    }
    else {
        lef -= (total_nodes(tree->child[0]) + 1);
        array<node*,2> res = split(tree->child[1],lef);
        tree->child[1] = res[0];
        calc(tree);
        return {tree,res[1]};
    }
    return {NULL,NULL};
}

node* merge(node *tree1, node *tree2) {
    if (tree1 == NULL) return tree2;
    if (tree2 == NULL) return tree1;
    push(tree1), push(tree2);
    if (tree1->priority < tree2->priority) {
        tree1->child[1] = merge(tree1->child[1],tree2);
        // debug(tree1->child[1]->sm);
        calc(tree1);
        return tree1;
    }     
    else {
        tree2->child[0] = merge(tree1,tree2->child[0]);
        calc(tree2);
        return tree2;
    }
}

node* rangeAdd(node* t, int l, int r, int b, int c) {
    array<node*,2> lef = split(t,l);
    array<node*,2> rig = split(lef[1],r-l+1);
    rig[0]->prop = (rig[0]->prop + c)%MOD;
    rig[0]->mul = (rig[0]->mul*b)%MOD;
    debug(rig[0]->prop,rig[0]->mul);
    return merge(lef[0],merge(rig[0],rig[1]));

}

pair<node*,int> rangeQuery(node* tree, int l, int r) {
    array<node*,2> lef = split(tree,l);
    array<node*,2> rig = split(lef[1],r-l+1);
    int ans = rig[0]->sm;
    node* root = merge(lef[0],merge(rig[0],rig[1]));
    return {root,ans};
}

int runcases(int qq)
{  
    
    int n,q;
    cin >> n >> q;

    vector<int> v(n);
    for (auto &s : v) cin >> s;

    node* root = NULL;
    for (auto x : v) {
        node *curr = new node(x);
        if (root == NULL) {
            root = curr;
            continue;
        }
        root = merge(root,curr);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int i,x;
            cin >> i >> x;
            int len = total_nodes(root);
            if (i == len) {
                node* curr = new node(x);
                if (root == NULL) root = curr;
                else root = merge(root,curr);
            }
            else {
                node* curr = new node(x);
                if (i == 0) {
                    root = merge(curr,root);
                }
                else {
                    array<node*,2> lef = split(root,i);
                    root = merge(lef[0],merge(curr,lef[1]));
                }
            }
        }
        else if (type == 1) {
            int i;
            cin >> i;
            if (i == 0) {
                array<node*,2> res = split(root,1);
                root = res[1];

            }
            else {
                array<node*,2> res = split(root,i);
                array<node*,2> res2 = split(res[1],1);
                root = merge(res[0],res2[1]);

            }
        }
        else if (type == 2) {
            int l,r;
            cin >> l >> r;
            r--;
            array<node*,2> lef = split(root,l);
            array<node*,2> rig = split(lef[1],r-l+1);
            rig[0]->flip += 1;
            root = merge(lef[0],merge(rig[0],rig[1]));

        }
        else if (type == 3) {
            int l,r,b,c;
            cin >> l >> r >> b >> c;
            r--;
            root = rangeAdd(root,l,r,b,c);
        }
        else {
            int l,r;
            cin >> l >> r;
            r--;
            auto res = rangeQuery(root,l,r);
            root = res.first;
            debug(l,r,root->sm);
            cout << res.second << nl;
        }
    }

    return 0;
    
    
}

 
signed main()
{
    
    //..........Fast I/O.........//
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //..........................//

    int t;
    t = 1;

    for (int i = 1; i <= t; i ++) {
        runcases(i);
    }

    return 0;
 
}