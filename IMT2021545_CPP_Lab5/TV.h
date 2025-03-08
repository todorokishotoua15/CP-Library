#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#ifndef TV_H
#define TV_H
#include"Product.h"

class TV:public Product{
    private:
        // data that are exclusive to tv
        string brand;
        int size,rating;
    public:
        void set_valtv(string br,string ty,int si,int pr,int ra);  // setter

        // getter
        string getBrand();
        int getRating();
        int getSize();

        // method to print all the data
        void getInfo() override;
};
#endif