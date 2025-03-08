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
const int N = 1e5 + 2;
const ll neg_inf = -2e7 + 2;
const ll inf = 1e9 + 2;
const int mod = 1e7 + 7;
int n , m;
char v[1000][1000];
map<pair<int,int>,int> vis;
stack <char> s;


ll sum(ll k, ll g){
	ll s = 0;

	while (s <= g){

		s += k;
		
		if (s == g) break;
		k++;
		
	}
	cout << s << nl;
	if (s == g) {
		return s;
	}
	return s;
}

int main()
{
	//..........Fast I/O.........//
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
 	// ..........................//
 	
	int t,g;
	cin >> t >> g;
	sum(t,g);

	return 0;
}