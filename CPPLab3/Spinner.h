// Spinner header file
// Roll - IMT2021016
#ifndef SPINNER_H
#define SPINNER_H

#include "Cars.h"

using namespace std;

class Spinner : public Cars {
public:

	// Methods

	void set_data(int x, int y, string ornt);

	void move(int k, vector<int> lims) override;
};

#endif