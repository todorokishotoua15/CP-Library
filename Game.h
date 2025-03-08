#ifndef GAME_H
#define GAME_H

using namespace std;

class Game {
public:
	virtual void start();
	virtual void recharge(int amount);
	virtual string move_l();
	virtual string move_r();
	virtual string move_u();
	virtual string move_d();
};

#endif