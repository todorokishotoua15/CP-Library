#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.h"
#else
#define debug(x...)
#endif

#define int int64_t
#define ll long long
#define nl "\n"
#define FOR(i,b,c) for (int i = b; i < c; i++)
 
const int32_t MAXN = 1e7+1;
const int32_t eps = 1e-6;
const int N = 1e7;
const int M = 5e4+5;

static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%esp, (%0)\n"
        "mov %0, %%esp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%esp\n" : : "r"(send));
    free(stack);
}

int64_t sumAll(int64_t n) {
   return n * (n + 1) / 2;
}

int64_t sumOdd(int64_t n) {
   return sumAll(n + 1) - 2 * sumAll((n + 1) / 2);
}

int runcases(int qq)
{  
    

    int n,m,k;
    cin >> n >> m >> k;



    vector<vector<int>> v(n,vector<int>(m));
    vector<vector<array<int,2>>> mp(n*m+1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            mp[v[i][j]].push_back({i,j});
        }
    }



    auto getArea = [&](int m, int n, int a, int b, int64_t len) {
       int64_t area = 2 * sumOdd(2 * len - 1) + 2 * len + 1;
       if (a - len < 1) area -= sumOdd(2 * len + 1 - 2 * a);
       if (a + len > m) area -= sumOdd(2 * len + 1 - 2 * (m - a + 1));
       if (b - len < 1) area -= sumOdd(2 * len + 1 - 2 * b);
       if (b + len > n) area -= sumOdd(2 * len + 1 - 2 * (n - b + 1));


       if (len >= a + b) area += sumAll(len - (a + b) + 1);
       if (len >= a + n - b + 1) area += sumAll(len - (a + n - b + 1) + 1);
       if (len >= m - a + 1 + b) area += sumAll(len - (m - a + 1 + b) + 1);
       if (len >= m - a + 1 + n - b + 1) area += sumAll(len - (m - a + 1 + n - b + 1) + 1);
       return area;
   };

    auto brute_tot = [&] (int i, int j, int sz) -> int {
        int ans = 0;
        for (int i1 = 0; i1 < n; i1++) {
            for (int j1 = 0; j1 < m; j1++) {
                int dis = abs(i-i1) + abs(j-j1);
                ans += (dis<=sz);
            }
        }
        return ans;
    };

    auto cnt_smaller = [&] (int score) -> int {
        int ans = 0;
        for (int i = 1; i <= n*m; i++) {
            int sub = 0;
            for 
        }
    };
    
    cout << "Case #" << qq << ": "  << nl;

    return 0;
    
}

 
void main_()
{
    
    //..........Fast I/O.........//
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //..........................//

    // freopen("prime_subtractorization_input.txt", "r", stdin);
    // freopen("2_final.txt", "w", stdout);


    int t;
    cin >> t;

    for (int i = 1; i <= t; i ++) {
        runcases(i);
    }
    
    return;
 
}

signed main() {
    run_with_stack_size(main_,1024*1024*1024);
    return 0;
}