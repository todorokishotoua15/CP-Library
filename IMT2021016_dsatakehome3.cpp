// Q17 -> Modified Inversion pair 

#include <bits/stdc++.h>
using namespace std;

vector<long long> a;
int ans = 0;

// merge function of merge sort
void merge(int l, int r) {
    int mid = (l+r)/2;
    int i = l;
    int j = mid + 1;

    // counting inversion pair
    while (i <= mid && j <= r) {
        if (a[i] <= 2*a[j]) {
            i++;
        }
        else {
            j++;
            ans += mid-i+1;
        }
    }
        
        
    i = l;
    j = mid + 1;
    vector<int> merged;
    
    // Merging 2 sorted array
    while (i <= mid && j <= r) {
            
        if (a[i] <= a[j]) {
            merged.push_back(a[i]);
            i++;
        }
        else {
                
                
            merged.push_back(a[j]);
            j++;
        }
    }
        
    while (i < mid+1) {
        merged.push_back(a[i]);
        i++;
    }
        
    while (j < r +1) {
        merged.push_back(a[j]);
        j++;
    }
        
    for (int i = 0; i < merged.size(); i++) {
        a[i+l] = merged[i];
    }
        // for (int i = l; i <= r; i++) cout << a[i] << " ";
        // cout << endl;
}

// Recursive divide and conquer of merge sort 
void divconq(int l, int r) {
    if (l < r) {
        int mid = (l+r)/2;
        // calling function recursively on left half
        divconq(l,mid);
        // calling function recursively on right halg
        divconq(mid+1,r);
        // merging t
        merge(l,r);
    }        
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	divconq(0,a.size()-1);
	cout << ans << endl;
	return 0;
}