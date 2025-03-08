#include <bits/stdc++.h>
#include "TV.h"

using namespace std;


// TV class constructor
TV::TV(string brnd, string dis, int sz, int prc, int rt){
	// setting data
	set_brand(brnd);
    display = dis;
    size = sz;
    set_price(prc);
    rating  = rt;
}

// method to print all the info
string TV::info() {
	string inf = "TV " + get_brand() + " " + display + " " + to_string(size) + " " + to_string(get_price()) + " " + to_string(rating);
	return inf;
}

// getters
string TV::get_display() {
	return display;
}

int TV::get_size() {
	return size;
}

int TV::get_rating() {
	return rating;
}

//comparators exclusive to TV
bool TV::rating_compare(TV obj1, TV obj2) {
	if (obj1.get_rating() == obj2.get_rating()) {
		return (obj1.get_price() < obj2.get_price());
	}
	return (obj2.get_rating() < obj1.get_rating());
}
bool TV::size_compare(TV obj1, TV obj2) {
	return (obj1.get_size() < obj2.get_size());
}
bool TV::display_compare(TV obj1, TV obj2) {
	return (obj1.get_display() < obj2.get_display());
}


