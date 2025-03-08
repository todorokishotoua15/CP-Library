// Roll - IMT2021016
#include<bits/stdc++.h>
#include "Cars.h"
#include "Game.h"

using namespace std;

void Cars::set_pos(int x, int y, string ornt) { // set position of Car
	x_pos = x;
    y_pos = y;

    curr_x = x_pos;
    curr_y = y_pos;

    orient = ornt;
}

string Cars::get_ornt() { // Get orientation of car
	return orient;
}

void Cars::set_ornt(string ornt1) {  // Set orientation of car
	orient = ornt1;
}

vector<int> Cars::lims() {  // Get board limits by calling get_lims() of game.
	Game game = Game();
	vector<int> lims = game.get_lims();
	return lims;
}

vector<int> Cars::query() { // Query the current position of car
	vector<int> curr = {curr_x, curr_y};
	return curr;
}

void Cars::move(int k, vector<int> lims) { // Move the car by k steps
	// implementation left to derived classes
}