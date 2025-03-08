// Roll - IMT2021016
#ifndef FlightSimple_H
#define FlightSimple_H
#include "Game.h"
#include "Chargeable.h"

using namespace std;

class FlightSimple: public Game,Chargeable {
private:
	// data
	int speed, altitude;
	int amount;

public:
	// methods
	string check();
	void start() override;
	void recharge(int amount) override;
	string move_l() override;
	string move_r() override;
	string move_u() override;
	string move_d() override;

};

#endif