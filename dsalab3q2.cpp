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
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto &s : v) cin >> s;

	int i = 0;
	int j = 0;

	int dist_count = 0;
	int ans = 0;
	int fin_ans = 0;
	unordered_map <int,int> mp;


	while (j < n) {

		if (mp[v[j]] == 0) {
			mp[v[j]]++;
			j++;
			ans++;
			dist_count++;
		}
		else {
			mp[v[j]]++;
			j++;
			ans++;

		}
		
		while (dist_count > k) {
			
			mp[v[i]]--;
			if (mp[v[i]] == 0)dist_count--;
			ans--;
			i++;
		}
		fin_ans = max(fin_ans, ans);
		
		
	}

	cout << fin_ans << nl;
	
	return 0;

}