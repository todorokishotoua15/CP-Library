#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;

// Product class skeleton.
class Product {
	private:
		string brand;
		int price;
	public:
		// stters for common data
		void set_price(int prc) {
			price = prc;
		}

		void set_brand(string brnd) {
			brand = brnd;
		}

		string get_brand(); //same as type for mattress
		int get_price();

		// virtual functions with dummy returns
		virtual string get_display() {return "none";};
		virtual int get_size() {return 0;};
		virtual int get_rating() {return 0;};
		virtual int get_width() {return 0;};
		virtual int get_length() {return 0;};
		virtual int get_delivery() {return 0;};
		virtual string info() {return "none";};

		// comparators
		static bool brand_compare(Product obj1, Product obj2);
		static  bool price_compare(Product obj1, Product obj2);


		// sort function
		template<typename T> // sort on properties common to all class
		void general_sort(vector<T> &v, string t) {
			if (t == "Brand" || t == "Type") {
				stable_sort(v.begin(),v.end(),brand_compare);
			}
			else if (t == "Price") {
			    stable_sort(v.begin(), v.end(), price_compare);
			}
		} 

};

#endif