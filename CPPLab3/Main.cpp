// Roll - IMT2021016
#include <bits/stdc++.h>
#include "Game.h"

int main() {
	int x1,x2,y1,y2; //board limits
	cin >> x1 >> x2 >> y1 >> y2;

	int count; // number of cars
	cin >> count;

	Game game = Game(); 

	game.set_data(x1,x2,y1,y2);

	// Adding cars
	for (int i = 0; i < count; i++) {
		string type;
		cin >> type;

		int x, y;
		cin >> x >> y;

		string ornt;
		cin >> ornt;
		game.add_car(type,x,y,ornt);
	}

	int n, k; // Steps
	cin >> n >> k;

	game.move(n,k);

	vector<vector<int>> pos = game.positions();

	// Answer
	for (auto poss : pos) {
		cout << poss[0] << " " << poss[1] << "\n";
	}
}