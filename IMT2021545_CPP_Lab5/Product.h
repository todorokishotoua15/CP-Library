#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#ifndef PRODUCT_H
#define PRODUCT_H

class Product{
    protected:
        string type; int price; // data that are common among all the products
    public:
        //setters
        virtual void set_valtv(string b,string t,int,int,int) {};
        virtual void set_valmat(string,int,int,int,int) {};

        // getters
        virtual int getSize();
        virtual int getDeltime();
        virtual int getWidth();
        string getType();
        virtual string getBrand();
        int getPrice();
        virtual int getRating();
        virtual int getLength();

        // method to print all the info of the product
        virtual void getInfo() {};
};
#endif