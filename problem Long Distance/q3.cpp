#include <bits/stdc++.h>
#include "testlib.h"
 
#define forn(i, n) for (int i = 0; i < int(n); i++)

 
using namespace std;
 
 
int main(int argc, char* argv[]) {
    setName("Interactor for Long Distance.");
    registerInteraction(argc, argv);
    
    int queries = 60;
    // cout << queries << " " << endl << flush;
    
    int n = inf.readInt();
    int q = inf.readInt();
    cout << flush;
    cout << n << " " << " " << q << endl << flush;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        int a = inf.readInt();
        int b = inf.readInt();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // debug(adj);
    // diameter
    pair<int,int> lgst = {0,-1}; 
    function<void(int,int,int)> lg = [&] (int node, int p, int lv) {
        if (lv > lgst.second) {
            lgst = {node,lv};
        }
        for (auto x : adj[node]) {
            if (x != p) {
                lg(x,node,lv+1);
            }
        }
    };

    auto diam = [&] () -> pair<int,int>{
        lg(1,-1,0);
        pair<int,int> ans = {lgst.first,0};
        lgst = {0,-1};
        lg(ans.first, -1, 0);
        ans.second = lgst.first;
        return ans;
    };

    auto diameter = diam();

    function<int(int,int,int,int)> get_dis = [&] (int u, int v, int p, int lv) -> int{
        if (u == v) {
            return lv;
        }

        for (auto x : adj[u]) {
            if (x != p) {
                return get_dis(x, v, u, lv+1);
            }
        }
    };
    int ans1 = -1;
    function<int(int,int,int,int)> get_node = [&] (int node, int dis, int lv, int par) -> int {
        if (lv >= dis) {
            ans1 = node;
        }
        // cout << node << " " << lv << " " << dis << endl; 
        for (auto x : adj[node]) {
            if (x != par) {
                get_node(x, dis,lv+1, node);
            }
        }

        
    };

    // cout << diameter.first << " " << diameter.second << endl;
    while (true) {
        int type = ouf.readInt();
        queries--;
        if (type != 1 && type != 2) {
            quitf(_wa, "wrong input format");
        }
        if (type == 2) {
            string s = ouf.readToken();
            break;
        }
        if (queries < 0) {
            quitf(_wa, "took more than 60 queries");
        }

        int u = ouf.readInt();
        int d = ouf.readInt();

        if (u <=0 || d <= 0) {
            quitf(_wa, "wrong input format");
        }
        if (u > n) {
            quitf(_wa, "wrong input format");
        }

        ans1 = -1;
        get_node(u,d, 0, 0);
        cout << ans1 << endl;

    }
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    // int q = ((int)rnd.next())%(100000) + 1;
    // cout << n << endl;
    // shuffle(v.begin(), v.end());
    // int q = n-1;
    while (q--) {
        int node = rnd.next(1,n);
        cout << node << endl;
        int a = ouf.readInt();
        int b = ouf.readInt();
        if (a <=0 || b <= 0) {
            quitf(_wa, "wrong input format");
        }
        if (a > n || b > n) {
            quitf(_wa, "wrong input format");
        }
        int dis = max(get_dis(node, a, 0,0), get_dis(node, b, 0, 0));
        int act = max(get_dis(node, diameter.first, 0,0), get_dis(node, diameter.second, 0, 0));
        if (dis == act) {
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
            quitf(_wa, "Wrongly guessed the node");
        }
    }
    quitf(_ok, "ok");
    
}
