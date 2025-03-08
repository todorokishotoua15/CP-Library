#include <bits/stdc++.h>
#include "Product.h"
#include "TV.h"
#include "Mattress.h"



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

int main() {
	vector<TV> tvs;  // all tv and mattresses
	vector<Mattress> mat;
	

	while(1) {
		string name;
		cin >> name;

		if (name == "End") {
			break;
		}

		string brand_or_type;
		cin >> brand_or_type;

		// creating and adding corresponding products
		if (name == "TV") {
			string type;
			int size, price, rating;
			cin >> type >> size >> price >> rating;

			TV tv =  TV(brand_or_type, type,size,price,rating);
			tvs.push_back(tv);
		}

		else {
			int wid, len, deliver, price;

			cin >> wid >> len >> deliver >> price;

			Mattress mat1 =  Mattress(brand_or_type, wid, len, deliver, price);
			mat.push_back(mat1);
		}

	}

	// sorting and listing 
	while (1) {
		string name;
		cin >> name;


		if (name == "End") break;
		if (name == "TV") {
			string t1;
			cin >> t1;

			vector<TV> tv1 = tvs;
			
			TV temp_tv =  TV("","",0,0,0);  // dummy class for sorting
			
			temp_tv.custom_sort(tv1,t1);

			// cout << "HI" << endl;

			for (auto x : tv1) {
				cout << x.info() << endl;
			}

		}
		else {
			string t1;
			cin >> t1;

			vector<Mattress> mat1 = mat;
			
			Mattress mats = Mattress("",0,0,0,0);  //dummy class for sorting
			
			mats.custom_sort(mat1,t1);

			for (auto x : mat1) {
				cout << x.info() << endl;
			}
		}
	}
}