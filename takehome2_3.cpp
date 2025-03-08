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

int connected;
    
int cnt = 0;
map<pair<int,int>, int> mp;
vector<vector<int>> adj(N);
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    //cout << node << endl;
    for (auto x : adj[node]) {
        //cout << x << " " << vis[x] << endl;
        if (mp[{node,x}] == 0 && mp[{x,node}] == 0){
            cnt++;
            mp[{node,x}] = 1;
            mp[{x,node}] = 1;
        }
        if (vis[x] == 0) {
            dfs(x,adj,vis);
        }
    }
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> connections;
	vector<int> vis(n+1,0);
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	connected = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            //cout << i << endl;
            dfs(i,adj,vis);
            connected++;
        }
    }
    int ans = connected - 1;
    if (cnt < n-1) {
    	cout << -1 << nl;
        return 0;
    }
    cout << ans << nl;
    return 0;
}