#include<bits/stdc++.h>
#include "Game.h"
#include "RandomWalk.h"

using namespace std;

string RandomWalk::check() {
	if (j >= 19 || i >= 19) {
		return "Lost";
	}
	if (j == 0) {
		return "Won";
	}
	return "None";
}


void RandomWalk::start()  {
	i = 10;
	j = 10;
}

string RandomWalk::move_l()  {
	if (i > 0) {
		i--;
	}
	string res = check();
	return res;
}

string RandomWalk::move_r()  {
	i++;
	string res = check();
	return res;
}

string RandomWalk::move_u() {
	j++;
	string res = check();
	return res;
}

string RandomWalk::move_d() {
	j--;
	string res = check();
	return res;
}