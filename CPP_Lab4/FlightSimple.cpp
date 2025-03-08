// Roll - IMT2021016
#include<bits/stdc++.h>
#include "Game.h"
#include "FlightSimple.h"

using namespace std;


// recharge the game
void FlightSimple::recharge(int amt)  {
	amount = amt;
}

// start the game by setting initial conditions
void FlightSimple::start()  {
	speed = 0;
	altitude = 0;
}

// move left
string FlightSimple::move_l()  {
	if (amount == 0) {
		return "Game Over";
	}
	
	amount--;
	if (speed > 0) {
		speed--;
	
		if (speed == 0 && altitude == 0) {
			return "Won";
		}
		else if (speed == 0) {
			return "Lost";
		}
	}
	return "None";
	
}

// move right
string FlightSimple::move_r()  {
	if (amount == 0) {
		return "Game Over";
	}
	
	amount--;
	speed++;
	
	return "None";
}

// move up
string FlightSimple::move_u() {
	if (amount == 0) {
		return "Game Over";
	}
	amount--;
	if (altitude == 0) {
		if (speed > 2) {
			altitude++;
		}
	}
	else {
		altitude++;
	}
	
	return "None";
}

// move down
string FlightSimple::move_d() {
	if (amount == 0) {
		return "Game Over";
	}
	amount--;
	altitude--;
	
	if (altitude < 0) {
		return "Lost";
	}
	return "None";
}