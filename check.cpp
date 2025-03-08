#include<bits/stdc++.h>
using namespace std;
#define   Tasmi                  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define   ll                     long long int
#define   vll                    vector<ll>
#define   pb(x)                  push_back(x)
#define   MOD                    1000000007
#define   ff                     first
#define   ss                     second
#define   PI                     2*acos(0.0)
#define   testcase(t)            int t;cin>>t;while(t--)
#define   yes                    cout<<'YES'<<endl
#define   no                     cout<<'NO'<<endl
#define   gcd(a,b)               __gcd(a,b)
#define   lcm(a,b)               (a*b)/gcd(a,b)
#define   vsort(a)               sort (a.begin(),a.end())
#define   gvsort(a)              sort(a.begin(), a.end(), greater<ll>())
#define   reverse(a)             reverse(a.begin(),a.end())
#define   coutv(v)               for(auto it:v)cout<<it<<' '; cout<<endl;
#define   cinv(v)                for(auto &it:v) cin>>it;
#define   v_sum(a)               accumulate(a.begin(),a.end(),0LL)
#define   v_min(a)               *min_element (a.begin(),a.end())
#define   v_max(a)               *max_element (a.begin(),a.end())
#define   sp                     cout<<fixed<<setprecision(10)<<num<<endl
#define   mset(nam,val)          memset(nam, val, sizeof(nam))
const int  N = 2e6+10;
vll graph[N];
bool vis[N];
ll dist[N];
vll primes;
void solution()
{
    int n,k;
    cin>>n;
    int arr[n];
    string s1,s2;
    cin>>s1;
    int a=0,b=0,c=0,d=0,e=0,f=0;
    for(auto i:s1)
    {
        if(i=='T')
        {
            if(a==0)
                a=1;
            else
                f=1;
        }
        else if(i=='i')
        {
            if(b==0)
                b=1;
            else
                f=1;
        }
        else if(i=='m')
        {
            if(c==0)
                c=1;
            else
                f=1;
        }
        else if(i=='u')
        {
            if(d==0)
                d=1;
            else
                f=1;
        }
        else if(i=='r')
        {
            if(e==0)
                e=1;
            else
                f=1;
        }
        else
            f=1;
    }
    if(f==1||a!=1||b!=1||c!=1||d!=1||e!=1)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
}
int main()
{
    Tasmi;
    testcase(t)
    solution();
    return 0;
}
