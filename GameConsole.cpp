#include<bits/stdc++.h>
#include "Game.h"
#include "GameConsole.h"

using namespace std;

GameConsole::GameConsole() {
	key = "";
}

void GameConsole::add_game(Game &new_game) {
	game = new_game;
}

void GameConsole::start() {
	game.start();
}

string GameConsole::key_r() {
	string res = game.move_r();
	return res;
}
string GameConsole::key_l() {
	string res = game.move_l();
	return res;
}
string GameConsole::key_u() {
	string res = game.move_u();
	return res;
}
string GameConsole::key_d() {
	string res = game.move_d();
	return res;
}

string GameConsole::read(vector<string> v) {
	for (auto x : v) {
		if (x == "L") {
			string res = key_l();
			if (res == "None") {
				continue;
			}
			else {
				return res;
			}
		}

		if (x == "R") {
			string res = key_r();
			if (res == "None") {
				continue;
			}
			else {
				return res;
			}
		}

		if (x == "D") {
			string res = key_d();
			if (res == "None") {
				continue;
			}
			else {
				return res;
			}
		}

		if (x == "U") {
			string res = key_u();
			if (res == "None") {
				continue;
			}
			else {
				return res;
			}
		}
	}

	return "Game Over";
}