#include <bits/stdc++.h>
#include "Lemon.h"

using namespace std;

void Lemon::set_data(int x, int y, string ornt) {
	set_pos(x,y,ornt);
}

void Lemon::move(int k, vector<int> lims)   {
	string orient = get_ornt();

	vector<int> curr_pos = query();

	int steps = k;

	if (orient == "right") {
        while (curr_pos[0] < lims[1] && steps > 0) {
            curr_pos[0] = curr_pos[0]+1;
            steps--;
        }
    }

    else if (orient == "left") {
        while (curr_pos[0] > lims[0] && steps > 0) {
            curr_pos[0] = curr_pos[0]-1;
            steps--;
        }
    }

    else if (orient == "down") {
        while (curr_pos[1] < lims[3] && steps > 0) {
            curr_pos[1] = curr_pos[1]+1;
            steps--;
        }
    }

    else {
        while (curr_pos[1] > lims[2] && steps > 0) {
            curr_pos[1] = curr_pos[1]-1;
            steps--;
        }
    }

    set_pos(curr_pos[0], curr_pos[1], orient);
}