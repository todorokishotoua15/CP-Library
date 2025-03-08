#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include"Listing.h"

// adding values
void Listing::addTv(Product* tv) {
    tvs.push_back(tv);
}

void Listing::addMattress(Product* mat) {
    mats.push_back(mat);
}

//getting values
vector<Product*> Listing::getTvlist() {
    return tvs;
}
vector<Product*> Listing::getMatlist() {
    return mats;
}

// comparators
bool Listing::brandCompare(Product* obj1, Product* obj2) {
  return (obj1->getBrand() < obj2->getBrand());
}

bool Listing::priceCompare(Product* obj1, Product* obj2) {
  return (obj1->getPrice() < obj2->getPrice());
}

bool Listing::ratingCompare(Product* obj1, Product* obj2) {
  if (obj1->getRating() == obj2->getRating()) {
    return (priceCompare(obj1,obj2));
  }
  return (obj2->getRating() < obj1->getRating());
}

bool Listing::sizeCompare(Product* obj1, Product* obj2) {
  return (obj1->getSize() < obj2->getSize());
}

bool Listing::displayCompare(Product* obj1, Product* obj2) {
  return (obj1->getType() < obj2->getType());
}

bool Listing::deliveryCompare(Product* obj1, Product* obj2) {
  if (obj1->getDeltime() == obj2->getDeltime()) {
    return priceCompare(obj1,obj2);
  }
  return (obj1->getDeltime() < obj2->getDeltime());
}


// sorting
void Listing::sorting(vector<Product *> &prods, string param, string prod) {
    if (param == "Brand") {
        sort(prods.begin(), prods.end(), brandCompare);
    }
    else if (param == "Type") {
        sort(prods.begin(), prods.end(), displayCompare);
    }
    else if (param == "Size") {
        sort(prods.begin(), prods.end(), sizeCompare);
    }
    else if (param == "Rating") {
        sort(prods.begin(), prods.end(), ratingCompare);
    }
    else if (param == "DeliveryTime") {
        sort(prods.begin(), prods.end(), deliveryCompare);
    }
    else if (param == "Price") {
        sort(prods.begin(), prods.end(), priceCompare);
    }
}