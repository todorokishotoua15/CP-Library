#include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#define rep(i,a,b) for(int i = a; i < b; i ++)
#define ill long long int
#define ll long long
#define nl "\n"
#define el endl
#define pb push_back
using namespace std;
const ll N = 1e3 + 2;
const ll neg_inf = -2e7 + 2;
const ll inf = 1e17 + 2;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;

struct dsu
{
	vector<int> e;
	dsu(int n) {
		e = vector<int>(n+1,-1);
	}

	int get(int x) {
		if (e[x] < 0) {
			return x;
		}
		else {
			return get(e[x]);
		}
	}

	bool same_set(int a, int b) {
		return (get(a) == get(b));
	}

	bool unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) {
			return false;
		}
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

// dfs(int node, map<int,list<pair<int,int>>> adj, vector<bool> &visited, )
// {
// 	visited[node] = true;
// 	for (auto x : adj[node]) {
// 		if (!visited[x.first]){
// 			if (x.second == 0) {

// 			}
// 		}
// 	}
// }

int main()
{
	int n,k;
	cin >> n >> k;
	int flag = 0;
	dsu ds = dsu(n+1);
	int con = 0;
	for (int i = 0; i < n; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		
		if (z == 0) {
			ds.unite(x,y);
			flag = 1;
		}
	}
	vector<int> conn;
	for (auto x : ds.e) {
		int cnt = 0;
		if (x < -1) conn.push_back(ds.e[x]);

	}
	ll ans = 1;
	ll cnt = 0;
	for (auto c : conn) {
		for (int i = 0; i <k; i++) {
			ans = ans*c;
		}
		cnt += c;
	}

	ll tot = 1;
	for (int i = 0; i < k; i++) {
		tot = tot*n;
	}
	if (flag == 0) {
		cout << tot - n << nl;
		return 0;
	}
	cout << tot - ans - cnt << nl;

	return 0;

}