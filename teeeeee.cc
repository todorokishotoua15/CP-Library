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
const ll N = 1e3 + 2;
const ll neg_inf = -2e7 + 2;
const ll inf = 1e17 + 2;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;

int bsearch(vector<int>v,int val) {
  int low = 0;
  int high = v.size();

  while(low <= high) {
      int mid = (low+high)/2;
      if (val < v[mid]) {
          if (mid == 0) return mid;
          if (v[mid-1] < val) return mid-1;
          else {
            high = mid;
          }
      }
      else if (val > v[mid]) {
        if (mid == v.size() -1) return mid;
        if (v[mid+1] > val) return mid;
        else {
          low = mid;
        }
      }
      else if (val == v[mid]) {
        return mid;
      }
  }
}

int main()
{
	vector<int> v = {2,2,2};
	cout << bsearch(v,4) << nl;
}