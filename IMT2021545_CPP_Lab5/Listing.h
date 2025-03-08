#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#ifndef LISTING_H
#define LISTING_H
#include"Mattress.h"

class Listing{
    private:
        // Tv and Mattress Lists
        vector<Product *>tvs;
        vector<Product *>mats;
    public:

        // adding products
        void addTv(Product* pr);
        void addMattress(Product* mat);

        //getter
        vector<Product*> getTvlist();
        vector<Product*> getMatlist();

        // sorting function
        void sorting(vector<Product *> &prods, string param, string prod);

        // comparators
        static bool brandCompare(Product* obj1, Product* obj2);
        static bool priceCompare(Product* obj1, Product* obj2);
        static bool ratingCompare(Product* obj1, Product* obj2);
        static bool sizeCompare(Product* obj1, Product* obj2);
        static bool displayCompare(Product* obj1, Product* obj2);
        static bool deliveryCompare(Product* obj1, Product* obj2);

};
#endif