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
const ll N = 1e6 + 2;
const ll neg_inf = -2e7 + 2;
const ll inf = 1e17 + 2;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;
int swaps = 0;
void mult(int a[2][2], int b[2][2])
{
    int mul[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            mul[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                mul[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[i][j] = mul[i][j];
        }
    }
}

void power(int a[2][2], int n)
{
    if (n == 0 || n == 1) return;

    int m[2][2] = {{1,1}, {1,1}};
    power(a,n/2);
    mult(a,a);
    if (n%2 != 0) mult(a,m); 
}

void bubblesort(vector<int> &a)
{
	// T(n) = n-1 + T(n-1)
	// 		= O(n^2)
	for (int i = 0; i < a.size(); i++) {
		for (int j = i+1; j < a.size(); j++) {
				if (a[i] > a[j]) {
						swap(a[i],a[j]);
						swaps++;
				}
		}
	}
}

void insertionsort(vector<int> &a)
{
	// T(n) = n-1 + T(n-1)
	// T(n) = O(n^2)
	for (int i = 0; i < a.size(); i++) {
		int curr = a[i];
		int j = i -1;

		while (j >= 0 && curr < a[j]) {
			swap(a[j+1],a[j]);
			j--;
		}
	}
}

void merge(vector<int> &a1, int l, int r) 
{
	// cout << l << " " << r << nl;
	// for (int i = l; i <= r; i++) {
	// 	cout << a1[i] << " ";
	// }
	// cout << nl;
	int mid = (l+r)/2;
	int i = l;
	int j = mid + 1;
	vector<int> merged;
	while (i <= mid && j <= r) {
		if (a1[i] < a1[j]) {
			merged.push_back(a1[i]);
			i++;
		}

		else {
			merged.push_back(a1[j]);
			j++;
		}

	}
	while (i < mid+1) {
		merged.push_back(a1[i]);
		i++;
	}

	while (j < r + 1) {
		merged.push_back(a1[j]);
		j++;
	}

	for (int i = 0; i < merged.size();i++) {
		a1[l + i] = merged[i];
		// cout << a1[i] << " ";
	}
	// cout << nl;
}

void mergesort(vector<int> &a, int l, int r)
{
	// T(n) = 2T(n/2) + 2n
	// 		= O(nlogn)
	if (l < r) {
		int  mid = (l+r)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,r);
	}

}

int partition(vector<int> &a, int l, int r)
{
	int pivot = a[l];
	int i = l+1;
	int j = r;
	while (i <= j) {
		while (i <= j && a[i] <= pivot) {
			i++;
		}
		while (i <= j && a[j] > pivot) {
			j--;
		}
		if (i < j) {
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	i--;
	a[l] = a[i];
	a[i] = pivot;
	return i;
	
}

void quicksort(vector<int> &a, int l, int r)
{
	if (l < r) {
		int p = rand()%(r-l+1) + l;
		swap(a[l], a[p]);
		int k = partition(a,l,r);
		quicksort(a,l,k-1);
		quicksort(a,k+1,r);

	}
}

void countsort(vector<int> &a, int div)
{
	int b[11] = {0};
	vector<int> n(a.size());
	
	for (auto x : a) {
		b[(x/div)%10]++;
	}

	for (int i = 1; i < 10; i++) {
		b[i] += b[i-1];
	}
	// cout <<"hi"<< b[1] << nl;
	for (int i =a.size()-1; i >= 0; i--) {
		// cout << (a[i]/div)%10 << " " << b[((a[i]/div)%10)]<< nl;
		n[b[(a[i]/div)%10] - 1] = a[i];
		b[(a[i]/div)%10]--;
	}

	for (int i = 0; i < a.size();i++) {
		a[i] = n[i];
	}
}

void radixsort(vector<int> &a) {
	int n = a.size();
	int m = *max_element(a.begin(), a.end());
	for (int i = 1; m/i > 0; i = i*10) {
			countsort(a,i);

	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &s : v) cin >> s;

	// bubblesort(v);
	// insertionsort(v);
	// quicksort(v, 0, n-1);
	// countsort(v);
	radixsort(v);
	for (auto x : v) cout << x << " ";
	cout << nl;
	// cout << swaps << nl;

}

