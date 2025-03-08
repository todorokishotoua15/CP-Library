// Q9 -> height of tree using the given preorder traversal

#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int height = -1; // initializing answer


	stack<pair<int,int>> st;  // using stack and pairs


	for (auto x : s) {
		st.push(make_pair(x,0)); // putting character in stack with its counter 0


		while (!st.empty()) {
			auto tp = st.top();

			// Pop top element if it is zero
			if (tp.first == '0') {
				st.pop();
				if (!st.empty())st.top().second++;
			}

			// Pop top element if its second time we are visiting it second time
			else if (st.top().second == 2) {
				st.pop();
				if (!st.empty())st.top().second++;
			}

			// Else break out of loop
			else {
				break;
			}
		}
		int curr = st.size(); // current size of stack
		height = max(height, curr);  // take maximum of all stack sizes
	}

	cout << height << endl;
}