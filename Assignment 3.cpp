/* Imagine a publishing company which does marketing for book and audio cassette versions.
 * Create a class publication that stores the title (a string) and price (type float) of publications.
 * From this class derive two classes: book which adds a page count (type int) and
 * tape which adds a playing time in minutes (type float).
 * Write a program that instantiates the book and tape class,
 * allows user to enter data and displays the data members.
 * If an exception is caught, replace all the data member values with zero values.
*/

#include <QCoreApplication>
#include <iostream>
#include <string>
using namespace std;

class publication{
protected:
    string title;
    float price;

public:
//    publication(){
//        title = "";
//        price = 0.0;
//    }
//    publication(string t, float p){
//        title = t;
//        price = p;
//    }

    void getdata(){
        string t;
        float p;

        cout<< "Enter title of publication: ";
        getline(cin, t);
        cout<< "Enter price of publication: ";
        cin>>p;

        title = t;
        price = p;

    }

    void display(){
        cout<< "Title: "<< title<<endl;
        cout<< "Price: "<< price<<endl;
    }

};

class book: public publication{
   int pagecount;
public:
//   book(){
//       pagecount = 0;
//   }

//   book(string t, float p, int pc): publication(t, p){
//       pagecount = pc;
//   }

   void getdata(){
     publication::getdata();
     cout << "Enter Book Page Count: ";
     cin >> pagecount;
     cout<<endl;
    }

   void display(){
       publication::display();
       cout<< "Pages: "<< pagecount<<endl;
       cout<<endl;
   }

};

class tape: public publication{
   float time;
public:
//   tape(){
//       time = 0.0;
//   }

//   tape(string t, float p, float pt): publication(t, p){
//       time = pt;
//   }

   void getdata(){
     publication::getdata();
     cout << "Enter Playtime: ";
     cin >> time;
     cout<<endl;
    }

   void display(){
       publication::display();
       cout<< "Playtime: "<< time <<endl;
       cout<<endl;
   }

};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    tape t1;
    t1.getdata();
    t1.display();

    book b1;
    b1.getdata();
    b1.display();




    return a.exec();
}
