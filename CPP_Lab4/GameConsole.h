// Roll - IMT2021016
#ifndef GAMECONSOLE_H
#define GAMECONSOLE_H
#include "Game.h"

using namespace std;

class GameConsole {
private:
	// data
	string key;
	Game* game;

public:
	// methods
	GameConsole();
	void add_game(Game *new_game);
	void start();

	string read(vector<string> v);

	string key_r();
	string key_l();
	string key_u();
	string key_d();
	
};

#endif