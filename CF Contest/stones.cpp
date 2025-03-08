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
const int32_t MAXN = 1e7+1;
const int32_t eps = 1e-6;
const int N = 1e7+1;
const int M = 2e5+5;



ll runcases(int qq)
{  

    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &s : v) cin >> s;
    if (n == 2) {
        v[0] += v[1];
        v[1] = 0;
        cout << v[0] << " " << v[1] << nl;
        cout << nl;
        return 0;
    }
    if (n == 1) {
        cout << v[0] << nl;
        cout << nl;
        return 0;
    }
    int cnt = 10;
    while (true) {
        if (v[n-2] < v[n-1]) swap(v[n-1],v[n-2]);
        // debug(v);
        bool op = false;

        // fix last
        if (v[n-1]+v[n-2] > 1) {
            op = true;
            int mid1 = (v[n-1]+v[n-2])/2;
            int mid2 = (v[n-1]+v[n-2]+1)/2;
            v[n-2] = mid2, v[n-1] = mid1;
            // debug(v);
            v[n-2] = mid2-mid1, v[n-1] = 0;
            v[n-3] += mid1;
            // debug(v);
        }
        if (op) continue;
        

        // fix
        // during fix step, v[i] will always > v[i+1];
        for (int i = n-3; i >= 1; i--) {
            // debug(i,v[i],abs(v[i]-v[i+1]));
            if (abs(v[i]-v[i+1]) > 1) {
                int add = v[i] - (v[i]+v[i+1]+1)/2;
                // debug(add);
                v[i] -= add;
                v[i+1] += add;
                v[i+2] += add;
                int mi = min(v[i],v[i+1]);
                // debug(v);
                v[i-1] += mi;
                v[i] -= mi;
                v[i+1] -= mi;
                // debug(v);
                op = true;
                break;
            }
        }
        if (op) continue;
        for (int i = n-2; i >= 1; i--) {
            if (abs(v[i]-v[i+1]) <= 1 && min(v[i],v[i+1]) > 0) {
                int mi = min(v[i],v[i+1]);
                // debug(v);
                v[i-1] += mi;
                v[i] -= mi;
                v[i+1] -= mi;
                // debug(v);
                op = true;
                break;
            }
        }

        if (!op) break;
    }

    // debug(qq,v);
    for (auto x : v) cout << x << " ";
    cout << nl; 

    return 0;
}

 
signed main()
{
    
    //..........Fast I/O.........//
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //..........................//


 

    ll t ;
 
    cin >> t;
    // debug(t);


    // debug(t);
    for (int32_t i = 1; i <= t; i ++) {
        runcases(i);
    }
    
    return 0;
 
}