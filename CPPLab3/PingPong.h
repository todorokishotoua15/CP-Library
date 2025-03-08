// Ping Pong header file
// Roll - IMT2021016
#ifndef PINGPONG_H
#define PINGPONG_H

#include "Cars.h"

using namespace std;

class PingPong : public Cars {
public:

	// Methods

	void set_data(int x, int y, string ornt);

	void move(int k, vector<int> lims) override;
};

#endif