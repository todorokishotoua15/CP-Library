#include <bits/stdc++.h>
 
using namespace std;

template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
#define rep(i,a,b) for(int i = a; i < b; i ++)
#define ill long long int
#define ll long long
#define nl "\n"
#define el endl
#define pb push_back


 
const int N = 3e5 + 2;
const ll neg_inf = -2e7 + 2;
const ll inf = 1e18 + 1;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;

long long st[4*(100000)];
void build(int node, int l, int r) {
    if (l == r) {
        st[node] = 0;
        return;
    }
    int mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    st[node] = 0;
}

void update(int node, int l, int r, int pos) {
    if (l == r) {
        st[node] = 1;
        return;
    }
    int mid = (l+r)/2;
    if (pos <= mid) {
        update(2*node, l, mid, pos);
    }
    else {
        update(2*node+1,mid+1,r,pos);
    }
    st[node] = st[2*node]+st[2*node+1];
} 


long long ans = 0;

void query(int node, int l, int r, int i, int j) {
    if (l > r || i > j) return;
    if (l == i && r == j) {
        ans += st[node];
        return;
    }
    int mid = (l+r)/2;
    query(2*node, l, mid, i, min(mid,j));
    query(2*node+1,mid+1,r,max(mid+1,i), j);
}


long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int> v1 = nums1, v2 = nums2;
    map<int,int> pos;
    for (int i = 0; i < n; i++) {
        pos[v2[i]] = i;
    }
    vector<long long> before(n);
    build(1,0,n-1);
    for (int i = 0; i < n; i++) {
        int curr = pos[v1[i]];
        ans = 0;
        query(1,0,n-1,0,curr-1);
        before[i] = ans;
        update(1,0,n-1,curr);
    }
    build(1,0,n-1);
    vector<long long>after(n);

    for (int i = n-1; i >= 0; i--) {
        int curr = pos[v1[i]];
        ans = 0;
        query(1,0,n-1,curr+1, n-1);
        after[i] = ans;
        update(1,0,n-1,curr);
    }

    long long t = 0;

    for (int i = 0; i < n; i++) {
        t += (before[i]*after[i]);
    }
    
    return t;
}

int main() {
	int n;
	cin >> n;
	vector<int> nums1(n),nums2(n);
	for (auto &s : nums1) cin >> s;
	for(auto &s : nums2) cin >> s;

	cout << goodTriplets(nums1,nums2) << nl;

}