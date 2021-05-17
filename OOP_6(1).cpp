//============================================================================
// Name        : OOP_6(1).cpp
// Author      : Sejal
// Version     :
// Copyright   : Your copyright notice
// Description : Write C++ program using STL for sorting and searching user defined records
//such as personal records (Name, DOB, Telephone number etc) using vector container.
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Person{

private:
        int rollNo;
        string name;
        string dateOfBirth;

public:

    bool operator ==(const Person &student1){
         return (this->rollNo==student1.rollNo);
    }

    bool operator <(const Person &student1){
        return (this->rollNo < student1.rollNo);
    }


    friend ostream& operator <<(ostream &out, const Person &stu){
        out<<"\n\t\t"<<stu.rollNo<<"\t\t"<<stu.name<<"\t\t"<<stu.dateOfBirth;
        return out;
    }


    friend istream& operator >>(istream &in, Person &stu){
        cout<<"\nEnter roll number: ";
        cin>>stu.rollNo;
        cout<<"\nEnter name: ";
        cin>>stu.name;
        cout<<"\nEnter date of birth: (ddmmyy)";
        cin>>stu.dateOfBirth;
        return in;
    }


    void SetRoll(){
        cin>>this->rollNo;
    }


    int GetRoll(){
        return this->rollNo;
    }

};

bool Compare(Person& stu1, Person& stu2){
    return (stu1<stu2);
}


vector<Person> ReadData(){
    int total;
    Person stu;
    vector<Person> stuData;
    cout<<"\nEnter total students: ";
    cin>>total;
    for(int i=0;i<total;i++){
        cin>>stu;
        stuData.push_back(stu);
    }
    return stuData;
}


void PrintFunction(const Person& stu){
    cout<<stu;
}

void PrintData(const vector<Person> &stu){
    cout<<"\n\t\tROLL NO\t\tNAME\t\tDATE OF BIRTH";
    for_each(stu.begin(),stu.end(),PrintFunction);
}


void InsertData(vector<Person> &stu){
    Person temp;
    cin>>temp;
    stu.push_back(temp);
}


void SearchData(vector<Person> &stuData){
    Person temp;
    cout<<"\nEnter roll number to be searched: ";
    temp.SetRoll();


    vector<Person>::iterator looper;

    looper = find(stuData.begin(),stuData.end(), temp);

    if(looper != stuData.end()){
        cout<<"\n\n\t\tROLL NO\t\tNAME\t\tDATE OF BIRTH";
        cout<<*looper;
    }
    else
        cout<<"\nNot found!"<<endl;
}


void DeleteData(vector<Person> &stuData){
    Person temp;
    cout<<"\nEnter roll number to delete: ";
    temp.SetRoll();
    vector<Person>::iterator looper;

    looper = find(stuData.begin(), stuData.end(), temp);

    if(looper != stuData.end())
        stuData.erase(looper);
    else
        cout<<"\nNot found"<<endl;
}


inline void SortData(vector<Person> &stuData){
    sort(stuData.begin(), stuData.end(), Compare);

}


int main(){
    vector<Person> stuData;
    int ch;

    do{
        cout<<"\nMENU:";
        cout<<"\n1.Create \n2.Display \n3.Insert \n4.Delete \n5.Search \n6.Sort \n0.Quit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch){
            case 1:
                stuData = ReadData();
                break;

            case 2:
                PrintData(stuData);
                break;

            case 3:
                InsertData(stuData);
                break;

            case 4:
                DeleteData(stuData);
                break;

            case 5:
                SearchData(stuData);
                break;

            case 6:
                SortData(stuData);
                PrintData(stuData);
                break;

            default:
                cout<<"Enter valid choice."<<endl;
                break;
        }
    } while(ch != 0);

    return 0;
}

