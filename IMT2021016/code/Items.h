#ifndef ITEMS_H
#define ITEMS_H

#include <bits/stdc++.h>
using namespace std;

class Items {

protected:
	int id;
	string title;
	bool available;

public:
	Items(int id, string TITLE, bool AVAILABLE);
	int getId();
	string getTitle();
	bool getAvailable();
	void setAvailable(bool newValue);

};

#endif