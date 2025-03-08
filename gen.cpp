#include "random.h"
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// #include "../params.h"

int main(int, char **argv) {
	long long seed = 125;
	auto gen = Random(seed);

	int n = uniform_distribution<int>(1, 30);
	int q = uniform_distribution<int>(1, 30);
	printf("%d %d\n", n, q);
	
	std::vector<int> a(n);
	for (auto &i : a) i = uniform_distribution<int>(0, MOD - 1);
	
	for (int i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%d", a[i]);
	}
	puts("");
	
	int len = n;
	for (int i = 0; i < q; i++) {
		int t = 0;
		if (len) t = uniform_distribution(0, 4);
		
		if (t == 0) {
			int i = uniform_distribution<int>(0, len);
			int x = uniform_distribution<int>(0, MOD - 1);
			printf("%d %d %d\n", t, i, x);
			len++;
		} else if (t == 1) {
			int i = uniform_distribution<int>(0, len - 1);
			printf("%d %d\n", t, i);
			len--;
		} else {
			auto lr = uniform_distribution_pair<int>(0, len);
			if (uniform_distribution(0, 9) == 0) lr.first = 0;
			if (uniform_distribution(0, 9) == 0) lr.second = len;
			if (t == 3) {
				int b = uniform_distribution<int>(0, MOD - 1);
				int c = uniform_distribution<int>(0, MOD - 1);
				printf("%d %d %d %d %d\n", t, lr.first, lr.second, b, c);
			} else printf("%d %d %d\n", t, lr.first, lr.second);
		}
	}
	
	return 0;
}