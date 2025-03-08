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
 
int vis[1001][1001][4];

int d[1000][1000][4];
int main()
{
    int n,m,i,j,l;
    cin >> n >> m;string x;
    vector<string> v;
    for (i=0;i<n;i++)
    {
        cin >> x;
        v.push_back(x);
    }
    int x1,y1,x2,y2;
    for (i=0;i<n;i++)
    {
        for (j=0;j<v[i].size();j++)
        {
            if (v[i][j] == 'V')
            {
                x1 = i;
                y1 = j;
            }
            else if (v[i][j] == 'H')
            {
                x2 = i;
                y2 = j;
            }
        }
    }
    i=x1;j=y1;
    //cout << x1 << y1 << n << m;
    queue<vector<int>>q;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            for (int k=0;k<4;k++)
            {
                d[i][j][k] = -1;
            }
        }
    }
    for (i=0;i<4;i++)
    {
        q.push({x1,y1,i});
        d[x1][y1][i] = 0;
    }
    int k;
    //cout << q.size();
    //vector<int>t = q.front();
    //q.pop();
    //cout << t[0];cout << t[2];
    
    for (int i = 0; i <= n ;i++) for (int j = 0; j <= m; j++) for (int k = 0; k < 4; k++)vis[i][j][k] = 0;

    while(!q.empty())
    {
        vector<int>t;
        t = q.front();
        //cout << q.size() << " ";
        
        debug(t);
        
        q.pop();
        if (vis[t[0]][t[1]][t[2]] == 1) continue;
        vis[t[0]][t[1]][t[2]] = 1;
        //cout << t[0] << " " << t[1] << t[2];
        int t1=t[0];int t2 = t[1]+1;
        if (t2<m && t1 < n &&  t1 >=0 && t2 >=0 && v[t1][t2] != '*')
        {
            k=3;
            if (d[t1][t2][k] <0 || d[t1][t2][k] > d[t[0]][t[1]][t[2]] + (t[2] != k))
            {
                d[t1][t2][k] = d[t[0]][t[1]][t[2]] + (k != t[2]);
            //  cout << d[t1][t2][k] << " ";
            //  cout << "t1=" << " " <<t1 << " ";
               //     cout << "t2 = " << t2 << " " << endl;     
            q.push({t1,t2,k});
            }
        }
        t1 = t[0]+1;t2 = t[1];
        if (t1 < n && t2 < m && t1 >=0 && t2 >= 0 && v[t1][t2] != '*')
        {
            k = 1;
            if (d[t1][t2][k] < 0 || d[t1][t2][k] > d[t[0]][t[1]][t[2]] + (t[2] != k))
            {
                d[t1][t2][k] = d[t[0]][t[1]][t[2]] + (t[2] != k);
                //cout << d[t1][t2][k] << " ";
                //cout << "t1=" << t1 << " " << "t2=" << " " << endl;
            q.push({t1,t2,k});
            }
        }
        t1 = t[0]-1;t2 = t[1];
        if (t1>=0 && t2 < m && t2>=0 && t1 < n && v[t1][t2] != '*')
        {
            k=0;
            if (d[t1][t2][k] < 0 || d[t1][t2][k] > d[t[0]][t[1]][t[2]] + (t[2] != k))
            {
                d[t1][t2][k] = d[t[0]][t[1]][t[2]] + (t[2] != k);   
                //cout << d[t1][t2][k] << " ";
                //cout << "t1=" << t1 << "t2=" << t2 << endl;
            q.push({t1,t2,k});
            }
        }
        t1 = t[0];t2 = t[1]-1;
        if (t2>=0&& t1 < n && t1 >=0 && t2 < m && v[t1][t2] != '*')
        {
            k=2;
            if (d[t1][t2][k] < 0 || d[t1][t2][k] > d[t[0]][t[1]][t[2]] + (t[2] != k))
            {
                d[t1][t2][k] = d[t[0]][t[1]][t[2]] + (t[2] != k);
                //cout << d[t1][t2][k] << " ";
                //cout << "t1=" << t1 << "t2=" << t2 << endl;
            q.push({t1,t2,k});
            }
        }
    }
    int res = -1;
        for (i=0;i<4;i++)
    {
        if (d[x2][y2][i] != -1)
        {
        //cout << "Hi";
        if (res == -1 || d[x2][y2][i] < res)
        res = d[x2][y2][i];
        }
    }
    cout << res <<endl;
    return 0;
}
