// Roll - IMT2021016
#include <bits/stdc++.h>
#include "Game.h"
#include "Cars.h"
#include "Lemon.h"
#include "PingPong.h"
#include "Spinner.h"

using namespace std;

Game::Game() { // initialize cars to be an empty array
	cars = {};
}

void Game::set_data(int x1, int x2, int y1, int y2) { // set board limts
	x_lower = x1;
    x_higher = x2;
    y_lower = y1;
    y_higher = y2;
}

vector<int> Game::get_lims() {  // method to get board limit
	vector<int> lims = {x_lower, x_higher, y_lower, y_higher};

	return lims;
}

void Game::add_car(string type, int x, int y, string ornt) { // method to add car in the game
	if (type == "Lemon") {
		Lemon *lemon1 = new Lemon();
		lemon1->set_data(x,y,ornt);
		cars.push_back(lemon1);
	}
	else if (type == "PingPong") {
		PingPong *ping1 = new PingPong();
		ping1->set_data(x,y,ornt);
		cars.push_back(ping1);
	}
	else {
		Spinner *spin = new Spinner();
		spin->set_data(x,y,ornt);
		cars.push_back(spin);
	}
}

void Game::move(int n, int k) {  // move all cars
	vector<int> limits = get_lims();

	// Repeat the movement n times
	for (int i = 0; i < n; i++) {
		for (auto car : cars) {
			car->move(k,limits);
		}
	}
}

vector<vector<int>> Game::positions() { // Get the position of each car
	vector<vector<int>> pos;

	for (auto car : cars) {
		vector<int> pos1 = car->query();
		pos.push_back(pos1);
	}

	return pos;
}