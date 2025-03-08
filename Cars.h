#ifndef CARS_H
#define CARS_H

#include "Product.h"

using namespace std;

class Cars: public Product{
private:

	int x_pos, y_pos;
	string orient;
	int curr_x, curr_y;

public:

	void set_pos(int x, int y, string ornt);

	string get_ornt();

	void set_ornt(string ornt1);

	vector<int> lims();

	vector<int> query();

	void move(int k, vector<int> lims);

};
#endif