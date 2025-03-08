#include <bits/stdc++.h> 
using namespace std;

#define ll long long
#define nl "\n"
 
int n, m;
vector<string> v;
 
vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};
int vis[1001][1001][4];
ll d[1001][1001][4];
bool isvalid(int i, int j) {
    return (i < n && j < m && i >= 0 && j >= 0 && v[i][j] != '*');
}
 
int runcases(int qq)
{
    cin >> n >> m; 
 
    int st, en;
    int d1, d2;
 
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'V') {
                st = i, en = j;
            }
            if (s[j] == 'H') {
                d1 = i, d2 = j;
            }
        }
        v.push_back(s);
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                vis[i][j][k] = 0;
                d[i][j][k] = 1e18;
            }
        }
    }
    deque<vector<int>> q;
 
    d[st][en][0] = 0;
    d[st][en][1] = 0;
    d[st][en][2] = 0;
    d[st][en][3] = 0;
 
    q.push_back({st,en,0}); // ci, j, state = 0 - left, 1 - right, 2 - down, 3 - up;
    q.push_back({st,en,1});
    q.push_back({st,en,2});
    q.push_back({st,en,3});
    while (!q.empty()) {
        auto curr = q.front();
        q.pop_front();
        int i = curr[0];
        int j = curr[1];
        
        int state = curr[2];
        if (vis[i][j][state] == 1) continue;
        vis[i][j][state] = 1;
        //debug(i,j,state);
        if (isvalid(i+1,j)) {
            if (state != 2 && state != -1) {

                if (d[i+1][j][2] > d[i][j][state] + 1) {
                    cout << i+1 << " " << j << nl;
                    d[i+1][j][2] = d[i][j][state] + 1;
                }
                q.push_back({i+1,j,2});
            }
            else {
                if (d[i+1][j][2] > d[i][j][state]) {
                    d[i+1][j][2] = d[i][j][state];
                }
                q.push_front({i+1,j,2});
            }
        }
        if (isvalid(i-1,j)) {
            if (state != 3 && state != -1) {
                if (d[i-1][j][3] > d[i][j][state] + 1) {
                    cout << i+1 << " " << j << nl;
                    d[i-1][j][3] = d[i][j][state] + 1;
                }
                q.push_back({i-1,j,3});
            }
            else {
                if (d[i-1][j][3] > d[i][j][state]) {

                    d[i-1][j][3] = d[i][j][state];
                }
                q.push_front({i-1,j,3});
            }
        }
        if (isvalid(i,j+1)) {
            if (state != 1 && state != -1) {
                if (d[i][j+1][1] > d[i][j][state] + 1) {
                    cout << i+1 << " " << j << nl;
                    d[i][j+1][1] = d[i][j][state] + 1;
                }
                q.push_back({i,j+1,1});
            }
            else {
                if (d[i][j+1][1] > d[i][j][state]) {
                    d[i][j+1][1] = d[i][j][state];
                }
                q.push_front({i,j+1,1});
            }
        }
        if (isvalid(i,j-1)) {
            if (state != 0 && state != -1) {
                if (d[i][j-1][0] > d[i][j][state] + 1) {
                    cout << i+1 << " " << j << nl;
                    d[i][j-1][0] = d[i][j][state] + 1;
                }
                q.push_back({i,j-1,0});
            }
            else {
                if (d[i][j-1][0] > d[i][j][state]) {
                    d[i][j-1][0] = d[i][j][state];
                }
                q.push_front({i,j-1,0});
            }
        }
    }
   // debug(d[2][3]);
    ll ans = min(d[d1][d2][0], min(d[d1][d2][1], min(d[d1][d2][2], d[d1][d2][3])));
    cout << (ans == 1e18 ? -1 : ans) << nl;
 
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
