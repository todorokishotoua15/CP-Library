#include<bits/stdc++.h>
#include "Items.h"
#include "LibSys.h"

Items LibSys::getItem(int id) {
	int index = -1;
	for (int i = 0; i < itemList.size(); i++) {
		auto x = itemList[i];
		if (x.getId() == id) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		return Items(0,"-1", false);
	}
	else {
		return itemList[index];
	}
}

vector<Items> LibSys::listAllItems() {
	return itemList;
}

bool LibSys::modifyItem(int id, Items newItem) {
	int index = -1;
	for (int i = 0; i < itemList.size(); i++) {
		auto x = itemList[i];
		if (x.getId() == id) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		return false;
	}
	else {
		itemList[index] = newItem;
		return true;
	}
};

bool LibSys::deleteItems(int id) {
	int index = -1;
	for (int i = 0; i < itemList.size(); i++) {
		auto x = itemList[i];
		if (x.getId() == id) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		return false;
	}
	else {
		itemList.erase(itemList.begin()+index);
		return true;
	}
};

void LibSys::addItems(Items item) {
	itemList.push_back(item);
}