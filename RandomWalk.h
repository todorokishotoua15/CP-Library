#ifndef RANDOMWALK_H
#define RANDOMWALK_H
#include "Game.h"

using namespace std;

class RandomWalk: public Game {
private:
	int i,j;

public:

	string check();
	void start() override;
	string move_l() override;
	string move_r() override;
	string move_u() override;
	string move_d() override;

};

#endif