#include<bits/stdc++.h>
using namespace std;

 
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
 
 
const int N = 6e6 + 2;
const ll neg_inf = -2e7 + 2;    
const ll inf = 1e18 + 1;
const int mod = 998244353;
const int MOD = 1e9+7;
const int MAXN = 6e6+1;
const int eps = 1e-6;


ll runcases(ll qq)
{   
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &s : v) cin >> s;

    map<int,int> mp;
    for (auto x : v) mp[x]++;

    auto sqr = [&] (int a) -> int{
        int low = 0;
        int high = 1e10;
        while (low <= high) {
            int mid = (low + high)/2;
            if (mid*mid == a) {
                return mid;
            }
            if (mid*mid < a)
                low = mid+1;
            else 
                high = mid-1;
        }
        return -1;
    };

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;

        int d = x*x - 4*y;
        debug(x,y,d,sqr(d));
        if (sqr(d) == -1) {
            cout << 0 << " ";
        }
        else {
            int s = sqr(d);
            int a1 = (x+s)/2;
            int a2 = (x-s)/2;
            int cnt = mp[a1]+(a1 != a2 ? mp[a2] : 0);
            // debug(a1,a2,cnt);
            // cout << mp[a1]*(a1 != a2 ? mp[a2] : mp[a2]) << " ";
            if (a1 == a2) {
                cout << mp[a1]*(mp[a1]-1)/2 << " ";
            }
            else {
                cout << mp[a1]*mp[a2] << " ";
            }
        }

    }
    cout << nl;

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

    // cout << t << nl;
    for (ll i = 1; i <= t; i ++) {
        runcases(i);
    }
    
      return 0;
 
}