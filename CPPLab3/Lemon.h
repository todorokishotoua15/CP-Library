// Lemon Header file
// Roll - IMT2021016
#ifndef LEMON_H
#define LEMON_H

#include "Cars.h"

using namespace std;

class Lemon : public Cars {
public:

	// Methods
	
	void set_data(int x, int y, string ornt);

	void move(int k, vector<int> lims) override;
};

#endif