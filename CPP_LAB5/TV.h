#ifndef TV_H
#define TV_H
#include "Product.h"
#include <bits/stdc++.h>

using namespace std;

// TV class skeleton which derrives from product class
class TV : public Product {
private:
	string  display;
	int size,  rating;

public:
	TV(string brnd, string dis, int sz, int prc, int rt); // constructor to set the data

	string info() override; // method to print all the info

	// getters
	string get_display() override;

	int get_size() override;

	int get_rating() override;

	// rating compare is exclusive to TV 
	static bool rating_compare(TV obj1, TV obj2);
	static bool size_compare(TV obj1, TV obj2);
	static bool display_compare(TV obj1, TV obj2);

	// sort function to sort on properties that are exclusive to child;
	template<typename T>
	void custom_sort(vector<T> &v, string t) {
		// sort
		if (t == "Rating") {
			stable_sort(v.begin(), v.end(), rating_compare);
		}
		else if (t == "Size") {
			stable_sort(v.begin(), v.end(), size_compare);
		}
		else if (t == "Type") {
			stable_sort(v.begin(), v.end(), display_compare);
		}
		else {
			general_sort(v,t);
		}
		
	}

};

#endif