#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#pragma comment(linker, "/STACK:2000000")
#pragma comment(linker, "/HEAP:2000000")
#pragma comment(linker, "/STACK:268439551");
using namespace __gnu_pbds;
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
>
ordered_set;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x = (x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
#define rep(i,a,b) for(int i = a; i < b; i ++)
#define ill long long int
#define ll long long
#define int long long
#define nl "\n"
#define el endl
#define pb push_back
 
 
const int N = 3e5+1;
const ll neg_inf = -2e7 + 2;    
const ll inf = 1e18 + 1;
const int mod = 998244353;
const int MOD = 1e9+7;
const int MAXN = 6e6+1;
const int eps = 1e-6;

 
ll runcases(ll qq)
{   
    
    int n,x;
    cin >> n >> x;

    vector<int> v(n);
    for (auto &s : v) cin >> s;

    int l = 0, r = 1e10;

    int ans = 0;

    while (l <= r) {
        int mid = (l+r)/2;
        int am = 0;
        for (auto x : v) {
            if (x >= mid) continue;
            int emp = mid-x;
            am += emp;
        }
        if (am <= x) {
            l = mid+1;
            ans = mid;
        }
        else {
            r = mid-1;
        }
    }

    cout << ans << nl;

    return 0; 
    
}
 
signed  main()
{
    
    //..........Fast I/O.........//
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //..........................//


    ll t;

    cin >> t;

    // debug(dp);
    // cout << t << nl;
    for (ll i = 1; i <= t; i ++) {
        runcases(i);
    }
    cerr << "Time: " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << " ms\n";
    return 0;
 
}