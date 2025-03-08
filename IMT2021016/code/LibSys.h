#ifndef LIBSYS_H
#define LIBSYS_H

#include <bits/stdc++.h>
#include "Items.h"
using namespace std;


class LibSys {

protected:
	vector<Items> itemList;

public:
	Items getItem(int id);
	vector<Items> listAllItems();
	bool modifyItem(int id, Items newItem);
	bool deleteItems(int id);
	void addItems(Items item);
};

#endif