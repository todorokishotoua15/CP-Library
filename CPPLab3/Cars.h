// Cars header file
// Roll - IMT2021016
#ifndef CARS_H
#define CARS_H

using namespace std;

class Cars {
private:
	// data
	int x_pos, y_pos;
	string orient;
	int curr_x, curr_y;

public:

	// Methods

	void set_pos(int x, int y, string ornt);

	string get_ornt();

	void set_ornt(string ornt1);

	vector<int> lims();

	vector<int> query();

	virtual void move(int k, vector<int> lims); // virtual method, to be overriden by derived classes

};
#endif