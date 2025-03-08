#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i ++)
#define ill long long int
#define ll long long
#define nl "\n"
#define el endl
#define pb push_back
using namespace std;
const ll N = 1e6 + 2;
const ll neg_inf = -2e7 + 2;
const ll inf = 1e17 + 2;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto &s : v) cin >> s;

	vector<int> v1(m);
	for (auto &s : v1) cin >> s;

	unordered_map <int,int> mp;
	
	for (auto x : v) {
		mp[x]++;
	}

	for (auto d : v1) {
		if (mp[d] == 0) {
			cout << "NO" << nl;
			return 0;
		}
		else {
			mp[d]--;
		}
	}

	cout << "YES" << nl;
	return 0;
}

