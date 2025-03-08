// Q34 - Maximum Icecream Bars

#include<bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
	int n, c; // n = length and c = number of coins
	cin >> n >> c;
	vector<int> v(n); // price list

	for (auto &s : v) cin >> s;
	sort(v.begin(), v.end());
	long long ans = 0;

	// Iterating and finding number of elements we can take
	for (auto x : v) {
        if (x <= c) {
            ans++;
            c-= x;
        }
    }

    cout << ans << nl;
}