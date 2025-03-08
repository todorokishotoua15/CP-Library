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
#define ll long long
using namespace std;
const int mod = 1e9 + 7;

dfs(int node, map<int,list<int>> &adj , map<int,list<int>> &parent, bool &visited, int par, vector<int> &lastlayer)
{
	if (par != 0){
		parent[node].push_back(par);
	}
	visited[node] = true;
	if (adj[node].size() == 1){
		lastlayer.push_back(node);
	}
	for (auto s : adj[node] ) {
		if (!visited[s]) {
			dfs(s,adj,parent,visited,par,lastlayer);
		}
	}
}

runcases()
{
	bool visited[4e5 + 2];
	rep(i,0,visited.size()){
		visited[i] = false;
	}
	map<int,list<int>> adj;
	int n, k;
	cin >> n >> k;
	int dfscall = 0;
	rep(i,0,n-1){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		dfscall = u;
	}
	map<int, list<int>> parent;
	vector<int> lastlayer;
	int par = 0;
	dfs(dfscall, adj, parent, visited,par,lastlayer);
	
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		runcases();
	}
}

