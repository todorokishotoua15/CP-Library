#include <bits/stdc++.h>
#include "Items.h"
#include "ItemTypes.h"

string Periodicals::getType() {
	return type;
}

void Periodicals::setType(string newType) {
	type = newType;
}

Periodicals::Periodicals(int id, string TITLE, bool AVAILABLE,string type) : Items(id, TITLE, AVAILABLE) {
	type = type;
}