#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
namespace __gnu_pbds{
          typedef tree<long long,
                       null_type,
                       less_equal<long long>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;

#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

 
void __print32_t(int32_t x) {cerr << x;}
void __print32_t(long x) {cerr << x;}
void __print32_t(long long x) {cerr << x;}
void __print32_t(unsigned x) {cerr << x;}
void __print32_t(unsigned long x) {cerr << x;}
void __print32_t(unsigned long long x) {cerr << x;}
void __print32_t(float x) {cerr << x;}
void __print32_t(double x) {cerr << x;}
void __print32_t(long double x) {cerr << x;}
void __print32_t(char x) {cerr << '\'' << x << '\'';}
void __print32_t(const char *x) {cerr << '\"' << x << '\"';}
void __print32_t(const string &x) {cerr << '\"' << x << '\"';}
void __print32_t(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print32_t(const pair<T, V> &x) {cerr << '{'; __print32_t(x.first); cerr << ','; __print32_t(x.second); cerr << '}';}
template<typename T>
void __print32_t(const T &x) {int32_t f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print32_t(i); cerr << "}";}
void _print32_t() {cerr << "]\n";}
template <typename T, typename... V>
void _print32_t(T t, V... v) {__print32_t(t); if (sizeof...(v)) cerr << ", "; _print32_t(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print32_t(x)
#else
#define debug(x...)
#endif
 
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
#define rep(i,a,b) for(int32_t i = a; i < b; i ++)
#define ill long long int32_t
#define ll long long
#define int int64_t
#define nl "\n"
#define el endl
#define pb push_back
#define FOR(a,b,c) for (int32_t a = b; a < c; a++)
using namespace std;
 
 
// const int32_t N = 3e5+1;
const ll neg_inf = -2e7 + 2;    
const ll inf = 1e18 + 1;
// const int32_t mod = 998244353;
// const int32_t MOD = 1e9+7;
const int32_t MAXN = 4e6+1;
const int32_t eps = 1e-6;
const int N = 5e3+5;
const int M = 5e4+5;

struct StringHashing {

    pair<vector<ll>, vector<ll>> compute_hash(string const& s) {
        const int n = s.size();
        const int p = 53;  // 53 if both uppercase and lowercase are present
        const int m = 1610612741;
        vector<long long> pow(n);

        pow[0] = 1;
        for (int i = 1; i < n; i++) {
            pow[i] = (pow[i-1]*p)%m;
        }
        vector<long long> hash(n+1, 0);
        for (int i = 0; i < n; i++) {
            hash[i+1] = (hash[i] + (s[i] - 'a' + 1)*pow[i])%m;
        }
        return {hash, pow};
    }

};

ll runcases(int qq)
{  
    
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);

    for (int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<char> val(n);
    for (auto &s : val) cin >> s;

    for (auto &s : adj) {
        sort(s.begin(),s.end());
    }

    vector<int> st(n+1),ed(n+1);

    int timer = 0;
    string s = "";
    auto dfs = [&] (auto self, int node, int p) -> void {
        st[node] = s.size();
        timer++;
        
        for (auto x : adj[node]) {
            if (x != p) {
                self(self,x,node);
            }
        }
        
        s += val[node-1];
        ed[node] = int(s.size())-1;
    };


    dfs(dfs,1,-1);

    string rev = s;
    reverse(rev.begin(),rev.end());

    StringHashing sh1,sh2;
    auto p1 = sh1.compute_hash(s);
    auto p2 = sh2.compute_hash(rev);

    int p = 53;  // 53 if both uppercase and lowercase are present
    int m = 1610612741;

    auto hash1 = p1.first, hash2 = p2.first;
    auto pow1 = p1.second, pow2 = p2.second;

    auto gethash1 = [&](int l, int r) -> ll {
        ll h = (hash1[r] - hash1[l] + m)%m;
        h = (h * pow1[n-l-1])%m;
        return h;
    };

    auto gethash2 = [&](int l, int r) -> ll {
        ll h = (hash2[r] - hash2[l] + m)%m;
        h = (h * pow2[n-l-1])%m;
        return h;
    };

    auto ispalin = [&](int l, int r) -> bool {
        ll h1 = gethash1(l,r);
        ll h2 = gethash2(n-r,n-l);
        return (h1 == h2);
    };

    int q;
    cin >> q;
    debug(s);
    while (q--) {
        int node;
        cin >> node;
        int l = st[node], r = ed[node];
        debug(node,l,r);
        cout << ispalin(l,r+1) << nl;
    }

    return 0;
}

 
signed main()
{
    
    //..........Fast I/O.........//
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //..........................//


 

    ll t ;
 
    t = 1;

    // debug(t);
    for (int32_t i = 1; i <= t; i ++) {
        runcases(i);
    }
    
    return 0;
 
}