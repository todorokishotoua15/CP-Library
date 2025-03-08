#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

#define rep(i,a,b) for(int i = a; i < b; i ++)
#define ill long long int
#define ll long long
#define nl "\n"
#define el endl
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
 
const ll N = 2e5 + 2;
const ll neg_inf = -2e7 + 2;
const ll inf = 1e17 + 2;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;


typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
>
ordered_set;
    
 
 
int runcases(int q)
{
    int n,x,y;
    cin >> n >> x >> y;
    if (x == y) {
        cout << 0 << nl;
        return 0;
    }
    
    cout << (int)(n*y)/(y+1) << nl;
    return 0;
    
}
 
int main()
{
  //..........Fast I/O.........//
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  // ..........................//
  
  int t;
 
  cin >> t;
  // cout << t << nl;
  for (int i = 1; i <= t; i ++) {
    
    runcases(i);
  }
 
  return 0;
 
}