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
const ll N = 2e5 + 2;
const ll neg_inf = -2e7 + 2;
const ll inf = 1e17 + 2;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;

int partition(vector<int> &s, int l, int r)
{
	int i = l+1;
	int j = r;
	int pivot = s[l];
	while (i <= j) {
		while (i <= j && s[i] <= pivot) {
			i++;
		}
		while (i <= j && s[j] > pivot) {
			j--;
		}
		if (i < j) {
			swap(s[i],s[j]);
			i++;
			j--;

		}
		
	}
	i--;
	s[l] = s[i];
	s[i] = pivot;
	return i;

}

int RandSelect(vector<int> &s, int l, int r, int i)
{
	if (l < r)
	{int p = rand()%(r-l+1) + l;
		swap(s[l], s[p]);
		int k = partition(s,l,r);
		if (r-k+1 == i) cout << "hk" << nl;
		else if (i < r-k+1) return RandSelect(s,k+1,r,i);
		else return RandSelect(s,l,k-1,(i-r+k-1));
	}

}

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (auto &s: v) cin >> s;

	cout << RandSelect(v,0,n-1,k) << nl;

}