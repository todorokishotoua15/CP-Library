#include<bits/stdc++.h>
#include "Mattress.h"

using namespace std;

// setting data
Mattress::Mattress(string typ, int wid, int len, int deliver, int pric) {
	set_brand(typ);
    width = wid;
    length = len;
    set_price(pric);
    delivery = deliver;
}

// method to print the info
string Mattress::info() {
	string inf = "Mattress " + get_brand() + " " + to_string(width) + " " + to_string(length) + " " + to_string(delivery) + " " + to_string(get_price());
	return inf;
}

// getters

int Mattress::get_width() {
	return width;
}

int Mattress::get_length() {
	return length;
}

int Mattress::get_delivery() {
	return delivery;
}

// comparator exclusive to mattress
bool Mattress::delivery_compare(Mattress obj1, Mattress obj2) {
	if (obj1.get_delivery() == obj2.get_delivery()) {
		return obj1.get_price() < obj2.get_price();
	}
	return (obj1.get_delivery() < obj2.get_delivery());
}
