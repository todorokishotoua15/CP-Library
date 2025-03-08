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
using namespace std;

void dfs(int node, int parent, vector<int> &ans, map <pair<int,int>,int> &pos,bool flag, map<int,list<int>> &adj) {
	if (parent != 0) {
		if (flag) {
			ans[pos[{parent,node}]] = 2;
			flag = false; 
		}
		else {
			ans[pos[{parent,node}]] = 3;
			flag = true;
		}
	}
	for (auto x : adj[node]) {
		if (x != parent) {
			dfs(x,node,ans,pos,flag,adj);
		}
	}
}



void run_cases()
{
	int n; cin >> n;
	map <int,list<int>> adj;
	map <pair<int,int>,int> pos;
	vector <int> ans(n-1);
	int q = 0;
	rep(i,0,n-1) {
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		pos[{x,y}] = i;
		pos[{y,x}] = i;
	}
	int leaf;
	for (int i = 1; i < n+1; ++i){
		if (adj[i].size() == 1) {
			leaf = i;
		}
		if (adj[i].size() > 2) {
			q = -1;
			break;
		}
	}
	if (q == -1) {
		cout << q ;
	}
	else {
		dfs(leaf,0,ans,pos,true,adj);
		rep(i,0,n-1) {
		cout << ans[i] << " ";
	}
	}
	
	


}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		run_cases();
		cout << el;
	}
}