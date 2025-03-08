#include<bits/stdc++.h>

#define rep(i,a,b) for(int i = a; i < b; i ++)
#define ill long long int
#define ll long long
#define nl "\n"
#define el endl
#define pb push_back
using namespace std;
 
const int N = 3e5 + 2;
const ll neg_inf = -2e7 + 2;
const ll inf = 1e18 + 1;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;

struct nd {
	ll first;
	int second;
	ll pushed;
};

nd st[4*N];
vector<int> v;
ll ans = 1e9;

void build(int node, int l, int r) {
	if (l == r) {
		st[node].first = 0;
		st[node].second = v[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*node, l, mid);
	build(2*node+1, mid+1, r);

	st[node].first = st[2*node].first + st[2*node+1].first;
	st[node].second = min(st[2*node].second, st[2*node+1].second);
}

void get_sm_i(int node, int l, int r, int val, int pos) {
	//cout << l << " " << r << " " << val << " " << pos << endl;
	if (r <= pos || ans != 1e9 || l > r || st[node].second >= val) {
		return;
	}
	if (l == r) {
		ans = l;
		return;
	}
	int mid = (l+r)/2;
	get_sm_i(2*node,l,mid,val,pos);
	get_sm_i(2*node+1,mid+1,r,val,pos);
}

void lazy(int node, int l, int r, int i, int j, int num, int done) {
	cout << l << " " << r << " " << i << " " << j << " " << num << " " << done << nl;
	if (l > r || i > j) return;
	if (l == i && r == j) {
		//cout << l << " " << r << " " << i << " " << j << " " << done << nl;
		st[node].first = ((num)*(num+1))/2 - ((done)*(done+1))/2;
		done += (r-l+1);
		return;
	}
	int mid = (l+r)/2;
	lazy(2*node, l, mid, i, min(mid,j),num, done);
	lazy(2*node+1, mid+1,r,max(i,mid+1),j,num,done);
}
ll query_ans = 1e9;
void query(int node, int l, int r, int pos) {
	if (l > r || query_ans != 1e9) return;
	if (l == r && l == pos) {
		query_ans = v[l] + st[node].first + st[node].pushed;
		return;
	}
	int mid = (l+r)/2;
	if (st[node].first != 0) {
		int dist;
		int nm = (r-l);
		ll sub = ((nm)*(nm+1))/2;
		dist = ((st[node].first) - sub)/(nm+1);
		ll lefpush;
		ll rigpush;
		int lfnm = (mid-l);
		lefpush = (((dist+lfnm)*(dist+lfnm+1))/2) - ((dist-1)*(dist))/2;
		rigpush = st[node].first - lefpush;
		st[node].first = 0;
		st[2*node].pushed += lefpush;
		st[2*node+1].pushed += rigpush;
	}
	if (pos <= mid) {
		query(2*node, l, mid, pos);
	}
	else {
		query(2*node+1, mid+1, r, pos);
	}
}

int main() 
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	build(1,0,n-1);
	lazy(1,0,n-1,5,7,3,0);
	cout << st[7].first << nl;
	query(1,0,n-1,6);
	cout << query_ans << nl;
	
}