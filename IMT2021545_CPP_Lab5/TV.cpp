#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include"TV.h"

void TV::set_valtv(string br,string ty,int si,int pr,int ra)
{
  // setting all the relevant information
  type=ty;
  price=pr;
  brand=br;
  size=si;
  rating=ra;
}

// getters
string TV::getBrand()
{
  return brand;
}

int TV::getRating()
{
  return rating;
}

int TV::getSize()
{
  return size;
}

// method to print all the information
void TV::getInfo() {
    string inf = "TV " + getBrand() + " " + getType() + " " + to_string(getSize()) + " " + to_string(getPrice()) + " " +  to_string(getRating());
    cout << inf << endl;
}
