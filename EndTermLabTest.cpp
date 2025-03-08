#include<bits/stdc++.h>
using namespace std;

#define nl "/n"
#define ll long long

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

struct node {
	int val;
    node *left;
    node *right;
  	node *par;
    node(int x) : val(x), left(nullptr), right(nullptr) {}
    node(int x, node *left, node *right) : val(x), left(left), right(right) {}
};

node build(vector<int> &v) {
	int n = v.size();

	queue<node> q;

	for (auto x : v) {
		node temp = node(x);
		q.push(temp);
	}
	queue<node> temp;
	while(!q.empty()) {
		node first = q.front();
		q.pop();
		//debug(first.val,q.size());
		
		if (q.empty()) {
			// done with all, return root
			if (temp.empty()) {
				debug(first.val, first.left->val, first.right->val);
				return first;
				
			}
			temp.push(first);
			while (!temp.empty()) {
				auto a = temp.front();
				q.push(a);
				temp.pop();
			}
			continue;

		}
		node second = q.front();
		q.pop();
		//debug(second.val,q.size(),temp.size());

		int val = max(first.val, second.val);

		node temp1 = node(val);
		temp1.left = &first; temp1.right = &second;
		// debug(val,first.val,second.val);
		// debug(temp1.val);
		temp.push(temp1);
		if (q.empty()) {
			while (!temp.empty()) {
				auto a = temp.front();
				//debug(a.val);
				q.push(a);
				temp.pop();
			}
		}
	}

}

map<node*,int> lv;

// level order traversal

bfs(node* root) {
	queue<node*> q;
	lv[root] = 0;
	q.push(root);
	while (!q.empty()) {
		auto curr = q.front();
		cout << curr->val << nl;
		q.pop();
		if (curr->left) {q.push(curr->left); lv[curr] = lv[root] + 1;}
		if (curr->right) {q.push(curr->right); lv[curr] = lv[root] + 1;}
	}
}

// finding length in order(n) by finding LCA.
int leng(node* a1, node* a2) {
	int ans = 0;
	if (lv[a1] > lv[a2]) {
		while (lv[a2] != lv[a1]) {
			a2 = a2->par;
			ans++;
		}
	}

	if (lv[a1] < lv[a2]) {
		while (lv[a2] != lv[a1]) {
			a1 = a1->par;
			ans++;
		}
	}

	if (lv[a1] == lv[a2]) {
		return ans;
	}

	while (lv[a1] != lv[a2]) {
		a1 = a1->par;
		a2 = a2->par;
		ans += 2;
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &s : v) cin >> s;

	node root = build(v);

	//bfs(&root);

	return 0;
}