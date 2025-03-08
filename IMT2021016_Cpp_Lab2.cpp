#include<bits/stdc++.h>
using namespace std;
#define nl "\n"

class Order {
	// Each order instance has its corresponding order number which
	// is initialized by keeping track of static variable "instance".
	
	// order structure :order number, name of item and number of item .

	// 	Only Dairy and Bakery can access it
	friend class Dairy;
	friend class Bakery;

private:
	static int instances;
	int number;
	string name;
	int item;

	// do the necessary initialization
	Order(string nam, int itm) {
		instances++;
		number = instances;
		name = nam;
		item = itm;
	}

	// method that returns name of order
	string get_name() {
		return name;
	}

	// method that returns the corresponding item number
	int get_item() {
		return item;
	}

	// method that returns corresponding order number
	int get_number() {
		return number;
	}
};

// Initializing static variables.
int Order::instances = 0;

class Bakery {
	// structure of dairy : id which keeps track of dairy number by using
	// static variable "instance" and list of order assigned to it.

	// Only Store can access this class
	friend class Store;

private:
	static int instances;
	int id;
	vector<Order> orders; 

	// do the initializations
	Bakery(){
		instances++;
	}

	void set_vals() {
		id = instances;
	}

	// create a new order
	void create_order(string name, int num) {
		Order order(name,num);
		orders.push_back(order);
	}

	// get the supplier id
	int get_id() {
		return id;
	}

	// process (print) the orders assigned to it
	void process() {
		cout << "Bakery " << id <<  nl;

		for (auto order : orders) {
			cout << "Order " << order.get_number() << " " << order.get_name() << " " << 
			order.get_item() << nl;
		}
		cout << nl;
	}

};

class Dairy {
	// structure of dairy : id which keeps track of dairy number by using
	// static variable "instance" and list of order assigned to it.


	// Only Store can access this class
	friend class Store;

private:
	static int instances;
	int id;
	vector<Order> orders; 

	// do the initializations
	Dairy(){
		instances++;
	}

	void set_vals() {
		id = instances;
	}

	// create a new order
	void create_order(string name, int num) {
		Order order(name,num);
		orders.push_back(order);
	}

	// get the supplier id
	int get_id() {
		return id;
	}

	// process (print) the orders assigned to it
	void process() {
		cout << "Dairy " << id <<  nl;

		for (auto order : orders) {
			cout << "Order " << order.get_number() << " " << order.get_name() << " " << 
			order.get_item() << nl;
		}
		cout << nl;
	}
};

// Initializing static variables.
int Dairy::instances = 0;
int Bakery::instances = 0;

class Store {

private:

	// bakery_count and dairy_count is used for indexing
	int bakery_num; 
	int dairy_num; 
	int bakery_count = 0; 
	int dairy_count = 0;

	// Store has all the supplier list with its count.
	vector<Bakery> bakeries;
	vector<Dairy> dairies;

public:
	// initialize
	Store(int b_num, int d_num) {
		bakery_num = b_num;
		dairy_num = d_num;

		// create new bakerie
		for (int i = 0; i < bakery_num; i++) {
			Bakery bakery_new;
			bakery_new.set_vals();
			bakeries.push_back(bakery_new);
		}

		// create new dairies
		for (int i = 0; i < dairy_num; i++) {
			Dairy dairy_new;
			dairy_new.set_vals();

			

			dairies.push_back(dairy_new);
		}

	}


	void process_order(string item_name, int item_number) {

		// Do the necessary forwarding
		if (item_name == "Milk" || item_name == "Butter") {
			Dairy curr = dairies[dairy_count];
			curr.create_order(item_name,item_number);
			dairies[dairy_count] = curr;
			dairy_count = (dairy_count+1)%(dairy_num);
		}
		
		else {
			Bakery curr = bakeries[bakery_count];
			curr.create_order(item_name,item_number);
			bakeries[bakery_count] = curr;
			bakery_count = (bakery_count+1)%(bakery_num);
		}
	}

	// Tell the supliers to process their orders
	void process_output() {
		for (auto bakery : bakeries) {
			bakery.process();
		}
		for (auto dairy : dairies) {
			dairy.process();
		}
	}


};

int main() {

	int bakery_num, dairy_num;
	cin >> bakery_num >> dairy_num;

	// Creating store instance
	Store store(bakery_num, dairy_num);

	while(true) {
		string item_name;
		cin >> item_name;

		if (item_name == "End") {
			break;
		}

		int item_number;
		cin >> item_number;

		// Give the order to store
		store.process_order(item_name, item_number);
	}

	// Tell the store that input has finished and now process all the orders
	store.process_output();
}