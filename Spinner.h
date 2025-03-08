#ifndef SPINNER_H
#define SPINNER_H

#include "Cars.h"

using namespace std;

class Spinner : public Cars {
public:
	void set_data(int x, int y, string ornt);

	void move(int k, vector<int> lims) override;
};

#endif