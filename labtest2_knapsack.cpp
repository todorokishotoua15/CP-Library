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

    int n,w1,w2,w3;
    cin >> n >> w1 >> w2 >> w3;
    vector<vector<vector<int>>> dp(w1+1,vector<vector<int>>(w2+1,vector<int>(w3+1,LLONG_MIN)));


    vector<int> w(n+1),p(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    // debug(w,p);
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        vector<vector<vector<int>>> n_dp(w1+1,vector<vector<int>>(w2+1,vector<int>(w3+1,LLONG_MIN)));
        for (int j = 0; j <= w1; j++) {
            for (int k = 0; k <= w2; k++) {
                for (int l = 0; l <= w3; l++) {
                    n_dp[j][k][l] = max(n_dp[j][k][l],dp[j][k][l]);
                    if (j-w[i]>=0) {
                        n_dp[j][k][l] = max(n_dp[j][k][l],dp[j-w[i]][k][l]+p[i]);
                    }
                    if (k-w[i]>=0) {
                        n_dp[j][k][l] = max(n_dp[j][k][l],dp[j][k-w[i]][l]+p[i]);
                    }
                    if (l-w[i]>=0) {
                        n_dp[j][k][l] = max(n_dp[j][k][l],dp[j][k][l-w[i]]+p[i]);
                    }
                }
            }
        }
        swap(dp,n_dp);
    }

    int ans = LLONG_MIN;

    for (int j = 0; j <= w1; j++) {
        for (int k = 0; k <= w2; k++) {
            for (int l = 0; l <= w3; l++) {
                ans = max(ans,dp[j][k][l]);
            }
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