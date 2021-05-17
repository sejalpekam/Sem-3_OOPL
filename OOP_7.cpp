//============================================================================
// Name        : OOP_7.cpp
// Author      : Sejal
// Version     :
// Copyright   : Your copyright notice
// Description : Write a program in C++ to use map associative container.
//The keys will be the names of states and the values will be the populations of the states.
//When the program runs, the user is prompted to type the name of a state.
//The program then looks in the map, using the state name as an index
//and returns the population of the state.
//============================================================================

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	string name;
	float population;
	int choice;
	bool start = true;

	string states[]={"Uttar Pradesh", "Maharashtra", "Bihar", "West Bengal",
			"Madhya Pradesh", "Rajasthan", "Tamil Nadu", "Karnataka", "Gujarat"};
	float populations[]={20.42, 11.42, 9.9, 9.03, 7.33, 6.89, 6.79, 6.41, 6.27};

	map<string, float, less<string>> mapStates;
	map<string, float, less<string>>::iterator iter;

	for(int j=0; j<9; j++){
		name = states[j];
		population = populations[j];
		mapStates[name] = population;
	}

	cout<<"MENU"
		  "\n1.Search population of a state."
		  "\n2.Display population of all states."
		  "\n0.Exit."<<endl;

	while(start){
		cout<<"\nEnter choice: ";
		cin>>choice;

		switch(choice){
		case 1:
			cout<<"\nEnter state: ";
			cin.ignore();
			getline(cin, name);
			population = mapStates[name];
			cout<<"Population of "<<name<<" is: "<<population<<" crores"<<endl;
			break;

		case 2:
			for(iter = mapStates.begin(); iter!= mapStates.end(); iter++){
				cout<<(*iter).first<<" : "<<(*iter).second<<" crores"<<endl;
			}
			break;

		case 0:
			start = false;
			break;

		default:
			cout<<"Enter valid choice."<<endl;
			break;
		}
	}

	return 0;
}

