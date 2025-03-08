#include<bits/stdc++.h>
#include "Cars.h"
#include "Game.h"

using namespace std;

void Cars::set_pos(int x, int y, string ornt) {
	x_pos = x;
    y_pos = y;

    curr_x = x_pos;
    curr_y = y_pos;


    orient = ornt;
}

string Cars::get_ornt() {
	return orient;
}

void Cars::set_ornt(string ornt1) {
	orient = ornt1;
}

vector<int> Cars::lims() {
	Game game = Game();
	vector<int> lims = game.get_lims();
	return lims;
}

vector<int> Cars::query() {
	vector<int> curr = {curr_x, curr_y};
	return curr;
}

void Cars::move(int k, vector<int> lims) {

}