#include <bits/stdc++.h>
#include "testlib.h"
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace std;
 
 
int main(int argc, char* argv[]) {
    setName("Interactor for Long Distance.");
    registerInteraction(argc, argv);
    
    int queries = 60;
    
    
    int n = inf.readInt();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int a = inf.readInt();
        int b = inf.readInt();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

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
        for (auto x : adj[node]) {
            if (x != p) {
                return get_dis(x, v, node, lv+1);
            }
        }
    };

    function<int(int,int,int,int)> get_node = [&] (int node, int dis, int lv, int par) -> int {
        if (lv >= dis) {
            return node;
        }
        for (auto x : adj[node]) {
            if (x != p) {
                return get_node(x, dis,lv+1 node);
            }
        }

        return -1;
    };


    while (true) {
        int type = ouf.readInt();
        queries--;
        if (type == 2) {
            string s = ouf.readToken();
            break;
        }
        if (queries < 0) {
            quitf(_wa, "took more than 60 queries")
        }

        int u = ouf.readInt();
        int d = ouf.readInt();

        int node = get_dis(u,d, 0, 0);
        cout << node << endl;

    }

    int q = rand()%(100000) + 1;
    cout << q << endl;
    while (q--) {
        int node = rand()%n + 1;
        cout << node << endl;
        int a = ouf.readInt();
        int b = ouf.readInt();
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
