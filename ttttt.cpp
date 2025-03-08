#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
 
#include <bits/stdc++.h>
 
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
#define nl "\n"
#define el endl
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
 
const int N = 3e5 + 2;
const ll neg_inf = -2e7 + 2;
const ll inf = 1e18 + 1;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;
 
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
 
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
>
ordered_set;
 
void bin(long long x, string &s) {
    if (x > 1) bin(x/2,s);
    int y = x%2;
    //cout << y;
    s += (y+'0');
    //cout << s << nl;
}
 
void factor(int n, vector<int> &fac) {
    
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            fac.push_back(i);
            n /= i;
        }
    }
    if (n > 1) fac.push_back(n);
    
}

int runcases(int qq)
{
    vector<int> v = {4,8,11,18};
    auto it = lower_bound(v.begin(), v.end(),8) - v.begin();
    cout << (it) << nl;
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
