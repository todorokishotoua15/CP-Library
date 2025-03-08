#ifndef ITEMTYPES_H
#define ITEMTYPES_H

#include <bits/stdc++.h>
#include "Items.h"
using namespace std;

class Books : public Items {};

class Periodicals : public Items {

protected:
	string type;
public:
	Periodicals(int id, string TITLE, bool AVAILABLE, string type);
	string getType();
	void setType(string newType);
};

class Game : public Items {};

#endif