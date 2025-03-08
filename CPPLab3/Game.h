// Game header file
// Roll - IMT2021016
#ifndef GAME_H
#define GAME_H

#include "Cars.h"
#include "Lemon.h"

using namespace std;

class Game {
private:
	// Data
	int x_lower, x_higher, y_lower, y_higher;
	vector<Cars*> cars;

public:

	// Methods

	Game();

	void set_data(int x1, int x2, int y1, int y2);

	vector<int> get_lims();

	void add_car(string type, int x, int y, string ornt);

	void move(int n, int k);

	vector<vector<int>> positions();
};

#endif