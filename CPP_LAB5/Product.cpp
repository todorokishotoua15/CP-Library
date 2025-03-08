#include<bits/stdc++.h>
#include "Product.h"

using namespace std;

//getters for common data
int Product::get_price() {
    return price;
}

string Product::get_brand() {
    return brand;
}

// making comparators that are common to all the products, if they are different, then base class will override it.
bool Product::brand_compare(Product obj1, Product obj2) {
    return (obj1.get_brand() < obj2.get_brand());
}

bool Product::price_compare(Product obj1, Product obj2) {
    return (obj1.get_price() < obj2.get_price());
}
