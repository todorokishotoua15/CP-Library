#include<bits/stdc++.h>
#define nl "\n"
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);

	for (auto &s : v) cin >> s;

	sort(v.begin(), v.end()); 

	// bounds for binary search
	int l = 0;
	int r = v[n-1];

	// initializing answer to infinty
	int ans = 1e9;

	// One element edge case
	if (l == r) {
		ans = (v[0] == 0 ? 0 : 1);
	}

	// Binary Search
	while (abs(l) < abs(r)) {

		if (r-l == 1) {

			int mid = l;
			int curr = 0;
			for (auto x  : v) {
				if (x >= mid) curr++;
			}

			if (curr <= mid) {
				ans = min(ans,mid);
				break;
			}

			mid = r;
			curr = 0;
			for (auto x  : v) {
				if (x >= mid) curr++;
			}

			if (curr <= mid) {
				ans = min(ans,mid);
				break;
			}

			break;


		}

		int mid = (l+r)/2;

		int curr = 0;
		for (auto x  : v) {
			if (x >= mid) curr++;
		}

		if (curr == mid) {
			ans = min(ans,mid);
			break;
		}

		else if (curr > mid) {
			l = mid;
		}

		else {
			r = mid;
		}
	}

	cout << ans << nl;
}