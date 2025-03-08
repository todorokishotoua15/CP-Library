#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
 
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
#define nl "\n"
#define el endl
#define pb push_back
using namespace std;
 
 
const int N = 1e6 + 2;
const ll neg_inf = -2e7 + 2;    
const ll inf = 1e18 + 1;
const int mod = 998244353;
const int MOD = 1e9+7;
const int MAXN = 1e6+1;
const int eps = 1e-6;

ll runcases(ll qq)
{   
    // for (ll i = 2; i <= 2000; i++) {
    //     for (ll j = 2; j <= 200000; j++) {
    //         if ((i^j) > i*j) {
    //             cout << i << " " << j << " " << (i^j) << " " << (i*j) << nl;
    //         }
    //     }
    // }
    cout << 1 << nl << 200000 << nl;
    for (int i = 1; i <= 200000; i++) {
        cout << 200000 << " ";
    }
    

    return 0;
}
 
int main()
{
    
    //..........Fast I/O.........//
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //..........................//


    ll t ;

    t = 1;
    // cout << t << nl;
    for (int i = 1; i <= t; i ++) {
        runcases(i);
    }
    
      return 0;
 
}