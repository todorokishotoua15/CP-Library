#include <bits/stdc++.h>
#include "Items.h"
#include "LibSys.h"
#include "ItemTypes.h"

#define nl "\n"


ostream & operator << (ostream &out, Items &c)
{
	if (c.getId() == 0) {
		out << "Item does not exists!!" << nl;
		return out;
	}
    out << "Id : " << c.getId() << "\n";
    out << "Title : " << c.getTitle() << "\n";
    out << "Avaiability : " << (c.getAvailable() ? "Yes" : "No") << "\n";

    return out;
}

ostream & operator << (ostream &out, Periodicals &c)
{
	if (c.getId() == 0) {
		out << "Item does not exists!!" << nl;
		return out;
	}
    out << "Id : " << c.getId() << "\n";
    out << "Type : " << c.getType() << "\n";
    out << "Title : " << c.getTitle() << "\n";
    out << "Avaiability : " << (c.getAvailable() ? "Yes" : "No") << "\n";

    return out;
}

istream & operator >> (istream &in, Items &c)
{
	string title, av;
	bool av1;
	int id;
	cout << "Enter id : ";
	in >> id;
    cout << "Enter title ";
    in >> title;
    cout << "Is the book available(Y/N) ? ";
    in >> av;
    c = Items(id,title, (av == "Y"));
    return in;
}

istream & operator >> (istream &in, Periodicals &c)
{
	string title, av;
	bool av1;
	int id;
	cout << "Enter id : ";
	in >> id;
    cout << "Enter title ";
    in >> title;
    string tp;
    cout << "Enter type : ";
    in >> tp;
    cout << "Is the book available(Y/N) ? ";
    in >> av;
    c = Periodicals(id,title, (av == "Y"),tp);
    return in;
}

void displayMenu() {
	cout << "---------------Library Management System-----------" << nl;
	cout << "Choose on of the option below : " << nl;
	cout << "Option 1 : List all the items" << nl;
	cout << "Option 2 : List detial of a particular item" << nl;
	cout << "Option 3 : Modify one of the items" << nl;
	cout << "Option 4 : Delete an item" << nl;
	cout << "Option 5 : Add an item" << nl;
	cout << "Option 6 : exit" << nl;
}

int main() {

	LibSys libsys;

	while (true) {
		displayMenu();
		int choice;
		cin >> choice;
		if (choice == 1) {
			if (libsys.listAllItems().size() == 0) {
				cout << "No items are present!!" << nl;
			}
			for (Items x : libsys.listAllItems()) {
				cout << x << nl;
				cout << "----------------------------" << nl;
			}
		}
		else if (choice == 2) {
			int id;
			cout << "Enter the id of the item that you want to get detail about : ";
			cin >> id;
			Items res = libsys.getItem(id);
			cout << res << nl;
			cout << "----------------------------" << nl;
		}
		else if (choice == 3) {

			int id;
			cout << "Enter the id of the item that you want to Modify : ";
			cin >> id;

			Items newItem(0,"", false);
			cin >> newItem;
			if (libsys.modifyItem(id, newItem)) {
				cout << "Modified Succesfully" << nl;
			}
			else {
				cout << "Some error occured" << nl;
			}
		}
		else if (choice == 4) {
			int id;
			cout << "Enter the id of the item that you want to Delete : ";
			cin >> id;
			if (libsys.deleteItems(id)) {
				cout << "Deleted Succesfully" << nl;
			}
			else {
				cout << "Some error occured" << nl;
			}
		}
		else if (choice == 5) {

			string t;
			cout << "Enter the type of item (book/periodical/game) : ";
			cin >> t;

			if (t == "book" || t == "game") {
				Items newItem(0,"", false);
				cin >> newItem;
				// cout << newItem;
				libsys.addItems(newItem);
			}
			else {
				Periodicals p1(0,"",false,"");
				cin >> p1;
				libsys.addItems(p1);
			}
			
		}
		else {
			break;
		}
	}
}