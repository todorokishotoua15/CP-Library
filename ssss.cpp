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
const ill N = 2e5 + 2;

int runcases()
{
	int n;
	cin >> n;
	n--;
	if (n < 11) {
		int ans = 0;
		for (int i = 1; i <= n+1; i++) {
				int j = n+1-i;
				if (i+j != n+1) continue;
				int curr = (i*j - ((__gcd(i,j))*(__gcd(i,j))))/(__gcd(i,j));
				//cout << i << " " << j << " " << curr << nl;
				ans = max(ans,curr);

			
		}
		cout << ans << nl;
		return 0;
	}
	if (n % 2 == 0) {
		int temp = (n-1)/2;
		cout << (ll)temp*(n - temp -1) << nl;
		return 0;
	}
	int temp = (n-2)/2;
	if (temp % 2 != 0) {
		temp = (n-1)/2;
		cout << (ll)(temp -1)*(temp + 1)<< endl;
	}
	else {
		int temp1 = (n-1)/2;
		cout << (ll)(temp1 + 2)*(temp1 -2) <<endl;
	}

	return 0;
}

int main()
{
	int t;
	cin >> t;
	
	while(t--){
		runcases();
	}
}