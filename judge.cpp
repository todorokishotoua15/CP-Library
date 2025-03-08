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
mt19937 mt(time(nullptr));  
int getval(int a, int b) {
    return mt()%(b-a+1)+a;
}

int runcases(int qq)
{  

    int n = getval(5,5);
    int a = 1, b = 4, c = 5;

    cout << n << endl;

    while (true) {
        string s;
        cin >> s;
        if (s == "ans") {
            int a1,b1,c1;
            cin >> a1 >> b1 >> c1;
            vector<int> v1 = {a,b,c}, v2 = {a1,b1,c1};
            if (v1 != v2) {
                cout << "Incorrect" << endl;
                break;
            }
            else {
                cout << "Correct" << endl;
                break;
            }
        }
        else {
            int l,r;
            cin >> l >> r;
            int xr = (l <= a && r >= a ? a : 0);
            xr ^= (l <= b && r >= b ? b : 0);
            xr ^= (l <= c && r >= c ? c : 0);
            cout << xr << endl;
        }
    }
 
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
    cout << t << endl;

    for (int i = 1; i <= t; i ++) {
        runcases(i);
    }
    
    return 0;
 
}