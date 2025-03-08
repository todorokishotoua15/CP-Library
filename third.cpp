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

map<int,int> mp;


ll runcases(int qq)
{  
    
    int n,k;
    cin >> n >> k;

    vector<int> v(n);
    for (auto &s : v) cin >> s;

    vector<int> lef(n,-1),rig(n,-1);

    int j = -1;
    for (int i = 0; i < n; i++) {
        if (j < i) {
            mp[v[i]]++;
            j = i+1;
        }
        while (j < n && mp.size() < k) {
            mp[v[j]]++;
            j++;
        }
        if (mp.size() < k) break;
        lef[i] = j-1;
        mp[v[i]]--;
        if (mp[v[i]] == 0) {
            mp.erase(mp.find(v[i]));
        }
    }

    mp.clear();

    j = -1;

    for (int i = 0; i < n; i++) {
        if (j < i) {
            mp[v[i]]++;
            j = i+1;
        }
        while (j < n && mp.size() <= k) {
            if (mp.size() == k) {
                if (mp.find(v[j]) == mp.end()) break;
            }
            mp[v[j]]++;
            j++;
        }
        if (mp.size() < k) break;
        rig[i] = j-1;
        mp[v[i]]--;
        if (mp[v[i]] == 0) {
            mp.erase(mp.find(v[i]));
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (lef[i] == -1) continue;
        ans += max(0ll,rig[i]-lef[i]+1);
    }

    cout << ans << nl;

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