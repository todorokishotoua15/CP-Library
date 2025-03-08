#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif

#define int int64_t
#define ll long long
#define nl "\n"
#define FOR(i,b,c) for (int i = b; i < c; i++)
 
const int32_t MAXN = 4e6+1;
const int32_t eps = 1e-6;
const int N = 2e5+1;
const int M = 27*3+2;


int runcases(int qq)
{  

    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &s : v) cin >> s;
    sort(v.begin(),v.end());
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int a1 = v[i], a2 = v[j];
            int currel = a1+a2;
            int currans = 2;
            vector<int> temp = {a1,a2};
            auto it = lower_bound(v.begin(),v.end(),currel);
            while (it != v.end()) {
                currans++;
                a1 = a2;
                a2 = *it;
                currel = a1+a2;
                temp.push_back(a2);
                it = lower_bound(v.begin(),v.end(),currel);
            }
            ans = max(ans,currans);
            debug(currans,temp);
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

    for (int i = 1; i <= t; i ++) {
        runcases(i);
    }
    
    return 0;
 
}