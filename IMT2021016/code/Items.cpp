#include<bits/stdc++.h>
#include "Items.h"
using namespace std;

Items::Items(int ID, string TITLE, bool AVAILABLE) {
	id = ID;
	title = TITLE;
	available = AVAILABLE;
}

int Items::getId() {
	return id;
}

string Items::getTitle() {
	return title;
}

bool Items::getAvailable() {
	return available;
}

void Items::setAvailable(bool newValue) {
	available = newValue;

}