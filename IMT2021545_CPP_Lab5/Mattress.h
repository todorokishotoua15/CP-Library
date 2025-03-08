#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#ifndef MATTRESS_H
#define MATTRESS_H
#include"TV.h"

class Mattress:public Product{
    private:
        int width,length,deltime; // all data exclusive to mattress
    public:
        void set_valmat(string,int,int,int,int) override; //setter
        // getter
        int getDeltime(); 
        int getWidth();
        int getLength();

        // method to print all the information
        void getInfo() override;
};
#endif