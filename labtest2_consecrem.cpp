#include<bits/stdc++.h>
using namespace std;

// #ifndef ONLINE_JUDGE
// #include "debug.h"
// #else
// #define debug(x...)
// #endif

#define int int64_t
#define ll long long
#define nl "\n"
#define FOR(i,b,c) for (int i = b; i < c; i++)
 
const int32_t MAXN = 4e6+1;
const int32_t eps = 1e-6;
const int N = 5000+1;
const int M = 5e4+5;


int runcases(int qq)
{  

    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &s : v) cin >> s;

    vector<int> suff(n);
    
    suff[n-1] = v[n-1];

    for (int i = n-2; i >= 0; i--) {
        suff[i] = suff[i+1];
        if (i%2==0) {
            suff[i] = max(suff[i],v[i]);
        }
    }

    int ans = INT_MIN;

    int currmax = INT_MIN;
    for (int i = 1; i < n-1; i++) {
        if (i%2 != 0) {
            ans = max(ans,currmax+v[i]+suff[i+1]);
        }
        else {
            currmax = max(currmax,v[i]);
        }
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


    int t;
    t = 1;

    // debug(t);
    for (int i = 1; i <= t; i ++) {
        runcases(i);
    }
    
    return 0;
 
}