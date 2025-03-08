#ifndef MATTRESS_H
#define MATTRESS_H

#include<bits/stdc++.h>
#include "Product.h"

using namespace std;

// Mattress class skeleton which derrives from product class
class Mattress: public Product {
private:
	string type;
	int width, length, price, delivery;

public:
	Mattress(string typ, int wid, int len, int deliver, int pric); // constructor to set all the data

	string info() override;  // method to print the info

	// getters
	int get_width() override;

	int get_length() override;

	int get_delivery() override;

	// delivery time is exclusive to Mattress 
	static bool delivery_compare(Mattress obj1, Mattress obj2);
	static bool wid_compare(Mattress obj1, Mattress obj2);
	static bool len_compare(Mattress obj1, Mattress obj2);

	// sort function to sort on properties that are exclusive to child;
	template<typename T>
	void custom_sort(vector<T> &v, string t) {
		// sort
		if (t == "DeliveryTime") {
			stable_sort(v.begin(), v.end(), delivery_compare);
		}
		else {
			general_sort(v,t);
		}
		
	}
};

#endif

