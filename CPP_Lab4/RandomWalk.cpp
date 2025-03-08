// Roll - IMT2021016
#include<bits/stdc++.h>
#include "Game.h"
#include "RandomWalk.h"

using namespace std;


// function to check the current state of game
string RandomWalk::check() {
	
	if (j >= 19 || i >= 19) {
		return "Lost";
	}
	if (j == 0) {
		return "Won";
	}
	return "None";
}

// starts by setting initial conditions
void RandomWalk::start()  {
	i = 10;
	j = 10;
}

// move left
string RandomWalk::move_l()  {
	if (i > 0) {
		i--;
	}
	string res = check();
	return res;
}

// move right
string RandomWalk::move_r()  {
	i++;
	string res = check();
	return res;
}

// move up
string RandomWalk::move_u() {
	j++;
	string res = check();
	return res;
}

// move down
string RandomWalk::move_d() {
	j--;
	string res = check();
	return res;
}