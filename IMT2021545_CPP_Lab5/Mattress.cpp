#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include"Mattress.h"

void Mattress::set_valmat(string ty,int wi,int le,int delt,int pr)
{
  // setting all the relevant data
  type=ty;
  width=wi;
  length=le;
  deltime=delt;
  price=pr;
}

// getters
int Mattress::getDeltime()
{
  return deltime;
}

int Mattress::getWidth()
{
  return width;
}

int Mattress::getLength()
{
  return length;
}

// method to print all the info
void Mattress::getInfo() {
    string inf = "Mattress " + getType() + " " + to_string(getWidth()) + " " + to_string(getLength()) + " " + to_string(getDeltime()) + " " + to_string(getPrice());
    cout << inf << endl;
}