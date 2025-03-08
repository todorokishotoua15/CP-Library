#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;

class Product {
	public:
		virtual string get_brand() {}; //same as type for mattress
		virtual string get_display() {};
		virtual string get_size() {};
		virtual int get_price() {};
		virtual int get_rating() {};
		virtual int get_width() {};
		virtual int get_length() {};
		virtual int get_delivery() {};

};

#endif