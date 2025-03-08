#ifndef LEMON_H
#define LEMON_H

#include "Cars.h"

using namespace std;

class Lemon : public Cars {
public:
	void set_data(int x, int y, string ornt);

	void move(int k, vector<int> lims) ;
};

#endif