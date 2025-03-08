#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
#define pr pair<ll,ll>
#define all(v) v.begin(),v.end()


void solve() {
  ll n;cin>>n;
  map<ll,ll>mp;
  vector<ll>a(n);for(auto &i:a)cin>>i;
  for(auto x:a)mp[x]++;
  ll num=1;
  for(auto x:a){
    num=num*x/__gcd(num,x);
    if(num>1e9){
        cout<<n<<endl;
        return;
    }
  }
  ll ans=0;
  map<ll,ll>cnt;
  for(auto x:mp){
    ll cur=x.F;
    ll tot=0;
    map<ll,bool>vis;
    for(auto j:mp){
        if(cur%j.F==0){tot+=j.S;vis[j.F]=true;}
        else{
            ll val=cur/__gcd(cur,j.F);
            val*=j.F;
            if(mp.find(val)==mp.end()){
                cur=val;
                tot+=j.S;
                vis[j.F]=true;
            }
        }
    }
    for(auto j:mp){
        if(!vis[j.F]){
            if(cur%j.F==0)tot+=j.S;
        }
    }
    if(mp.find(cur)==mp.end()){
        ans=max(tot,ans);
    }
  }
  cout<<ans<<endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++) solve();
}