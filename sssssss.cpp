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
const int neg_inf = -2e7 + 2;
const int mod = 1e9 + 7;

int main()
{
	map<int,list<int>> adj;
	adj[1] = {2,3,4,5};
	cout << adj[1][2];
}