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

 
ll n, x;
vector<ll> val;
vector<vector<int>> adj(N);
vector<ll> sub(N,0);
vector<int> vis(N,0);
ll subtree(int node) {
    vis[node] = 1;
    if (adj[node].size() == 1 && node != 1) {
        sub[node] = val[node-1];
        return sub[node];
    }
    sub[node] += val[node-1];
    for (auto x : adj[node]) {
        if (vis[x] == 0) {
            sub[node] += subtree(x);
        }
    }
 
    return sub[node];
}
ll doing = 0;
ll add = 1e9;
void dfs(int node) {
    doing++;
    vis[node] = 1;
    if (adj[node].size() != 3) {
        if (node == 1) {
            if (adj[node].size() != 2) {
                add = min(add,doing);
            }
        }
        else add = min(add,doing);
    }
    for (auto x : adj[node]) {
        if (vis[x] == 0)dfs(x);
    }
    doing--;
}
 
int runcases(int qq)
{
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        val.push_back(t);
    }
 
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    subtree(1);
    for (int i = 0; i <= n; i++) {
        vis[i] = 0;
    }
    dfs(1);
 

 
    ll ans = 0;
 
    for (int i = 1; i <= n; i++) { ans += sub[i]; }
 
    cout << ans + (add+1)*x << nl;
 
    return 0;
}
 
int main()
{
 
    
    //..........Fast I/O.........//
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // ..........................//
      
    int t;
     
    t = 1;
    // cout << t << nl;
    for (int i = 1; i <= t; i ++) {
        runcases(i);
    }
     
      return 0;
 
}
