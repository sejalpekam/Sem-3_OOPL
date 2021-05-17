//============================================================================
// Name        : File Handling.cpp
// Author      : Sejal
// Description : Write a C++ program that creates an output file, writes
//information to it, closes the file and open it again as an input file
//and read the information from the file.
//============================================================================

#include <fstream> //for file streams
#include <iostream>
using namespace std;

class person //class of persons
{
protected:
char name[80]; //person name
short age; //person age
public:

void getData() //get person's data
{
cout << "Enter name: "; cin >> name;
cout << "Enter age: "; cin >> age;
}

void showData() //display person data
{
cout << "Name: " << name << endl;
cout << "Age: " << age << endl;
}
};

int main()
{
person pers; //create person variable
cout<<"Enter details to be written in file:"<<endl;
pers.getData(); //get data for person

//create ofstream object
ofstream outfile("PERSON.DAT", ios::binary);

//write to it
outfile.write(reinterpret_cast<char*>(&pers), sizeof(pers));

//close outfile
outfile.close();

//create ifstream object
ifstream infile("PERSON.DAT", ios::binary);
cout<<"Contents on file:"<<endl;
//read stream
infile.read( reinterpret_cast<char*>(&pers), sizeof(pers) );

pers.showData(); //display person

return 0;
}

