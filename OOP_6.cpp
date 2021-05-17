//============================================================================
// Name        : OOP_6.cpp
// Author      : Sejal
// Version     :
// Copyright   : Your copyright notice
// Description : Write C++ program using STL for sorting and searching
//user defined records such as Item records
//(Item code, name, cost, quantity etc) using vector container.
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Item{
public:
	char name[20];
	int code;
	int cost;
	int quantity;

	bool operator ==(const Item &i1){
		if(code == i1.code)
			return 1;
		else
			return 0;
	}

	bool operator <(const Item &i1){
		if(code<i1.code)
			return 1;
		else
			return 0;
	}

};

vector<Item> vec;

void print(Item &i1){
	cout<<endl;
	cout<<"Item Name: "<<i1.name<<endl;
	cout<<"Item Quantity: "<<i1.quantity<<endl;
	cout<<"Item Cost: "<<i1.cost<<endl;
	cout<<"Item Code: "<<i1.code<<endl;
}

void display(){
	for_each(vec.begin(), vec.end(), print);
}

void insert(){
	Item i;
	cout<<"Enter Item Name: ";
	cin>>i.name;
	cout<<"Enter Item Quantity: ";
	cin>>i.quantity;
	cout<<"Enter Item Cost: ";
	cin>>i.cost;
	cout<<"Enter Item Code: ";
	cin>>i.code;
	vec.push_back(i);
}

void search(){
	vector<Item> :: iterator p;
	Item i;
	cout<<"\nEnter Item code to be searched: ";
	cin>>i.code;
	p = find(vec.begin(), vec.end(), i);

	if(p == vec.end()){
		cout<<"Item code not found."<<endl;
	}
	else{
		cout<<"Item code found."<<endl;
	}
}

void del(){
	vector<Item>::iterator p;
	Item i;
	cout << "\nEnter Item code of the Item to be deleted: ";
	cin >> i.code;
	p = find(vec.begin(), vec.end(), i);

	if (p == vec.end()) {
		cout << "Item code not found." << endl;
	}
	else {
		vec.erase(p);
		cout << "Item deleted." << endl;
	}
}

bool compare(const Item &i1, const Item &i2){
	return i1.cost < i2.cost;
}

int main() {
	int choice;
	bool start = true;
	cout<<"MENU"
		  "\n1.Insert."
		  "\n2.Display."
		  "\n3.Search."
		  "\n4.Sort."
		  "\n5.Delete."
		  "\n0.Exit."<<endl;

	while(start){
		cout<<"\nEnter choice: ";
		cin>>choice;

		switch(choice){
		case 1:
			insert();
			break;

		case 2:
			cout<<"Displaying all items:"<<endl;
			display();
			break;

		case 3:
			search();
			break;

		case 4:
			sort(vec.begin(), vec.end(), compare);
			cout<<"\nSorted on Cost: "<<endl;
			display();
			break;

		case 5:
			del();
			break;

		case 0:
			start = false;
			exit(0);

		}
	}

	return 0;
}
