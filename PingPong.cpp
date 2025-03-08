#include <bits/stdc++.h>
#include "PingPong.h"

using namespace std;

void PingPong::set_data(int x, int y, string ornt) {
	set_pos(x,y,ornt);
}

void PingPong::move(int k, vector<int> lims) {
	int total_steps = k;
    string orient = get_ornt();

   
    vector<int> curr_pos = query();
    

    string new_ornt;

    //Left-right movement only
    if (orient == "right" || orient == "left") {
        int go = (orient == "right" ? 1 : -1);

        //If at the edge of board, change the orientation
        if (go == 1) {
            int a = curr_pos[0];
            int b = lims[1];
            if (a == b) {
                go = -1;
            }
        }
        else {
            int a = curr_pos[0];
            int b = lims[0];
            if (a == b) {
                go = 1;
            }
        }
        //Simulating the movements
        while (total_steps > 0) {
            int moved = 0;
            if (go == 1) {
                int a = curr_pos[0];
                int b = lims[1];
                if (a == b) {
                    go = -1;
                }
                else {
                    curr_pos[0] = curr_pos[0]+1;
                    moved = 1;
                }
                
            }
            if (go == -1) {
                int a = curr_pos[0];
                int b = lims[0];
                if (a == b) {
                    go = 1;
                }
                else {
                    curr_pos[0] = curr_pos[0]-1;
                    moved = 1;
                }
                
            }

            //check if car cannot move any further
            if (curr_pos[0] == lims[0] && curr_pos[0] == lims[1]) {
                break;
            }
            if (moved == 1)total_steps -= 1;
        }
        new_ornt = (go == 1 ? "right" : "left");
    }

    //Up-down movement only
    else {
        int go = (orient == "down" ? 1 : -1); //Setting orientation

        if (go == 1) {
            if (curr_pos[1] == lims[3]) {
                go = -1;
            }
        }
        else {
            int a = curr_pos[1];
            int b = lims[2];
            if (a == b) {
                go = 1;
            }
        }

        //Simulating the movement
        while (total_steps > 0) {
            int moved = 0;
            if (go == 1) {
                int a = curr_pos[1];
                int b = lims[3];
                if (a == b) {
                    go = -1;
                }
                else {
                    curr_pos[1] = curr_pos[1]+1;
                    moved = 1;
                }
                
            }
            if (go == -1) {
                int a = curr_pos[1];
                int b = lims[2];
                if (a == b) {
                    go = 1;
                }
                else {
                    curr_pos[1] = curr_pos[1]-1;
                    moved = 1;
                }
                
            }
            //check if car cannot move any further
            if (curr_pos[1] == lims[2] && curr_pos[1] == lims[3]) {
                break;
            }
            if (moved == 1)total_steps -= 1;
        }
        new_ornt = (go == 1 ? "down" : "up");
    }

    set_pos(curr_pos[0], curr_pos[1], orient);
    set_ornt(new_ornt);
    
}