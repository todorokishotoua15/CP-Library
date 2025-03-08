// Roll - IMT2021016
#include <bits/stdc++.h>
#include "Spinner.h"

using namespace std;

void Spinner::set_data(int x, int y, string ornt) { // Set position of the car
	set_pos(x,y,ornt);
}

void Spinner::move(int k, vector<int> lims) { // Move the car
	int total_steps = k;
    string orient = get_ornt();

   
    vector<int> curr_pos = query();
    
    int go; //orientation varriable (1-right, -1-left, 2-down, -2 - up)

    //Setting the initial orientation
    if (orient == "right" ) {
        go = 1;
    }

    else if (orient == "left") {
        go = -1;
    }

    else if (orient == "down") {
        go = 2;
    }

    else {
        go = -2;
    }

    //If at the edge of the board, change the orientation
    if (go == 1) {
        if (curr_pos[0] == lims[1]) {
            go = 2;
        }
    }

    else if (go == 2) {
        if (curr_pos[1] == lims[3]) {
            go = -1;
        }
    }

    else if (go == -2) {
        if (curr_pos[1] == lims[2]) {
            go = 1;
        }
    }

    else {
        if (curr_pos[0] == lims[0]) {
            go = -2;
        }
    }
    //Simulating the movement
    while (total_steps > 0) {
        int moved = 0;
        if (go == 1) {
            if (curr_pos[0] == lims[1]) {
                go = 2;
            }
            else { 
                curr_pos[0] = curr_pos[0]+1;
                moved = 1;
            }
        }

        if (go == 2) {
            if (curr_pos[1] == lims[3]) {
                go = -1;
            }
            else {
                curr_pos[1] = curr_pos[1]+1;
                moved = 1;
            }
            
        }

        if (go == -1) {
            if (curr_pos[0] == lims[0]) {
                go = -2;
            }
            else {
                curr_pos[0] = curr_pos[0]-1;
                moved = 1;
            }
            
        }
        
        if (go == -2) {
            if (curr_pos[1] == lims[2]) {
                go = 1;
            }
            else {
                curr_pos[1] = curr_pos[1]-1;
                moved = 1;
            }
            
        }
        // check if car is stuck and cannot move
        if (curr_pos[0] == lims[0] && curr_pos[0] == lims[1]) {
            if (curr_pos[1] == lims[2] && curr_pos[1] == lims[3]) {
                break;
            }
        }

        //if car moved a step, then decrease the total steps, if not then it will move within next 3 iterations
        if (moved == 1)total_steps -= 1;
    }
    string new_ornt;
    if (go == 1) {
        new_ornt = "right";
    }
    else if (go == -1) {
        new_ornt = "left";
    }
    else if (go == 2) {
        new_ornt = "down";
    }
    else {
        new_ornt = "up";
    }

    set_pos(curr_pos[0], curr_pos[1], orient);
    set_ornt(new_ornt);
}