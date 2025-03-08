// Roll - IMT2021016
#ifndef RANDOMWALK_H
#define RANDOMWALK_H
#include "Game.h"

using namespace std;

class RandomWalk: public Game {
private:
	// data
	int i,j;  

public:
	
	// methods
	string check();
	void start() override;
	string move_l() override;
	string move_r() override;
	string move_u() override;
	string move_d() override;

};

#endif