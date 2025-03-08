#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
const int mx = 1e9;

bool patternfinder(vector<int> v) {
	int n = v.size();
	vector<int> pref_min(n,mx);
	pref_min[0] = v[0];
	stack<int> st;


	for (int i = 1; i <n; i++) {
		pref_min[i] = min(pref_min[i-1], v[i]);
	}

	for (int i = n-1; i >= 0; i--) {
		int currmin = -mx;
		if (i-1 >= 0)currmin = pref_min[i-1];
		else currmin = v[i];
		//cout << currmin << nl;
		while (!st.empty() && st.top() <= currmin) {
			//cout << st.top() << nl;
			st.pop();
		}

		if (!st.empty() && v[i] > st.top()) {
			return true;
		}

		st.push(v[i]);
	}

	return false;
}


int main()
{
	// for input first give length of array, then stream of numbers
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &s : v) cin >> s;

	cout << (patternfinder(v) == 1 ? "true" : "false") << nl;
}