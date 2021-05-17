//#include <QCoreApplication>
//#include <iostream>
//#include <string.h>
//using namespace std;

//class per_info
//{
//    string lic, dob, bldgrp;
//    public:
//    per_info(){
//        lic="NA";
//        dob="NA";
//        bldgrp="NA";
//    };
//    per_info(per_info &obj){
//            lic=obj.lic;
//            dob=obj.dob;
//            bldgrp=obj.bldgrp;
//    };
//    ~per_info() {
//          cout<<"\nDESTRUCTOR IS CALLED!!!!!"<<endl<<"RECORD DELETED SUCCESSFULLY"<<endl;
//    };

//    friend class student;
//};

//class student{
//    string name, address, year, div;
//        int roll_no;
//        long mob;
//        static int cnt;
//    public:
//        void create(per_info &);
//        void display(per_info &);

//        inline static void inccnt()
//        {
//            cnt++;
//        }
//        inline static void showcnt()
//        {
//            cout<<"\nTOTAL NO OF RECORDS ARE : "<<cnt;
//        }
//        student(){
//            name="NA";
//            address="NA";
//            year="SE COMPUTER";
//            div="NA";
//            roll_no=0;
//            mob=0;
//        };
//        student(student &obj){
//                 this->name=obj.name;
//                 this->address=obj.address;
//                 this->year=obj.year;
//                 this->div=obj.div;
//                 this->roll_no=obj.roll_no;
//                 this->mob=obj.mob;
//        };
//        ~student()
//        {
//            cout<<"\nDESTRUCTOR IS CALLED!!!"<<endl<<"RECORD DELETED SUCCESSFULLY"<<endl;
//        }
//    };
//int student::cnt;

//void student::create(per_info &obj)
//{
//    cout<<"\nNAME : ";
//    cin>>name;
//    cin.ignore();
//    cout<<"\nADDRESS : ";
////    cin>>address;
//    getline(cin, address);
//    cout<<"\nDATE OF BIRTH : ";
//    cin>>obj.dob;
//    cout<<"\nYEAR : ";
//    cin>>year;
//    cout<<"\nDIVISION: ";
//    cin>>div;
//    cout<<"\nROLL NUMBER : ";
//    cin>>roll_no;
//    cout<<"\nBLOOD GROUP : ";
//    cin>>obj.bldgrp;
//    cout<<"\nLICENCE NUMBER : ";
//    cin>>obj.lic;
//    cout<<"\nPHONE NUMBER : ";
//    cin>>mob;
//}


//void student::display(per_info &obj)
//{
//    cout<<"\n***********************"<<endl;
//    cout<<"\nNAME OF STUDENT : "<<name<<endl;
//    cout<<"\nADDRESS OF STUDENT : "<<address<<endl;
//    cout<<"\nDATE OF BIRTH : "<<obj.dob<<endl;
//    cout<<"\nYEAR : "<<year<<endl;
//    cout<<"\nDIVISION : "<<div<<endl;
//    cout<<"\nROLL NO : "<<roll_no<<endl;
//    cout<<"\nBLOOD GROUP : "<<obj.bldgrp<<endl;
//    cout<<"\nLICENCE NUMBER : "<<obj.lic<<endl;
//    cout<<"\nPHONE NUMBER : "<<mob<<endl;
//    cout<<"\n***********************"<<endl;
//}


//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    int n;
//    int ch;
//    char ans;

//    cout<<"\nENTER NO OF STUDENTS :";
//    cin>>n;
//    cout<<"\n***********************"<<endl;
//    student *sobj=new student[n];
//    per_info *pobj=new per_info[n];

//    do
//    {
//        cout<<"\n Menu \n 1. Create Database \n 2. Display Databse \n 3. Copy Constructor\n 4. Default Constructor \n 5. Delete (Destructor)"<<endl;
//        cout<<"\n Enter your Choice: ";
//        cin>>ch;
//        cout<<endl;
//        switch(ch)
//        {
//        case 1: // create database
//        {
//            for(int i=0;i<n;i++)
//            {
//                  cout<<"Enter data of student "<<i+1<<":"<<endl;
//                  sobj[i].create(pobj[i]);
//                  sobj[i].inccnt();

//            }
//        }
//           break;
//        case 2: // Display Database
//           {
//                sobj[0].showcnt();

//                for(int i=0;i<n;i++)
//                {
//                    sobj[i].display(pobj[i]);
//                }
//            }
//            break;
//         case 3: // Copy Constructor
//           {
//                student obj1;
//                per_info obj2;
//                obj1.create(obj2);
//                student obj3(obj1);		//invoking copy constructor of student info to copy contents from object 1 to 3

//                per_info obj4(obj2);		 //invoking copy constructor of personal info to copy contents from object 2 to 4
//                cout<<"\n Copy Constructor is called ";
//                obj3.display(obj4);
//           }
//           break;
//        case 4: // Default Constructor
//           {
//                student obj1;	//obj1 is invoking default constructor of class student
//                per_info obj2;	//obj2 is invoking default constructor of class personal
//                cout<<"\n Default Constructor is called ";
//                obj1.display(obj2);
//           }
//           break;
//        case 5: // destructor is called

//            delete [] sobj;			//invoking destructor and delete sobj dynamically
//            delete [] pobj;		//invoking destructor and delete pobj dynamically
//            break;
//       }				//end of switch case
//       cout<<"\n Want to continue:(y/n)"	     ;
//       cin>>ans;
//     }while(ans=='y') 	;


//    return a.exec();
//}

#include <QCoreApplication>
#include <iostream>
using namespace std;

class Student
{
    string name,class_name,dob,blood_group,address;
    int roll_no,license_num,division;
    long long ph_num;

    public:
    Student()
    {
        roll_no = 0;
        name = "";
        class_name = "";
        dob = "";
        blood_group = "";
        address = "";
        ph_num = 0;
        division = 0;
        license_num = 0;
    }

    Student(Student &obj)
    {
        this->name = obj.name;
        this->roll_no = obj.roll_no;
        this->class_name = obj.class_name;
        this->division = obj.division;
        this->dob = obj.dob;
        this->blood_group = obj.blood_group;
        this->address = obj.address;
        this->ph_num = obj.ph_num;
        this->license_num = obj.license_num;
        cout << "Copy constructor called!" <<endl;
    }

    ~Student()
    {
        cout << endl;
        cout << "Student " << name << " info is destroyed" << endl;
    }

    friend class display;
    friend class input;

    static void func()
    {
        cout << "Object of student created!" << endl;
    }

};

class display
{
public:
    inline void show(Student &s)
    {
        cout << "\nThe details of the student are:";
        cout << "\nRoll Number                   :" << s.roll_no;
        cout << "\nName                          :" << s.name;
        cout << "\nClass                         :" << s.class_name;
        cout << "\nDivision                      :" << s.division;
        cout << "\nDate of Birth                 :" << s.dob;
        cout << "\nBlood Group                   :" << s.blood_group;
        cout << "\nContact Address               :" << s.address;
        cout << "\nTelephone Number              :" << s.ph_num;
        cout << "\nDriving License No            :" << s.license_num << endl;
    }
};

class input
{
public:
    inline void getdata(Student &s)
    {
        cout << "Enter details of the student:";
        do
        {
            try
            {
                cout << "\nRoll number: ";
                cin >> s.roll_no;
                if (s.roll_no < 0)
                {
                    throw s.roll_no;
                }
            }
            catch(int roll_no)
            {
                cout<<"Roll number should be positive!\n";
            }
        } while(s.roll_no < 0);
        cout << "Name: ";
        cin.ignore();
        getline(cin,s.name);
        cout << "Class: ";
        cin >> s.class_name;
        cout << "Division: ";
        cin >> s.division;
        cout << "Date of Birth: ";
        cin >> s.dob;
        cout << "Blood Group: ";
        cin >> s.blood_group;
        cout << "Contact Address: ";
        cin.ignore();
        getline(cin,s.address);
        cout << "Telephone Number: ";
        cin >> s.ph_num;
        cout << "Driving License No: ";
        cin >> s.license_num;
    }
};

int main(){
    int total, i;
    cout << "Enter total no. of students: ";
    cin >> total;
    Student* a = new Student[total];
    input in;
    display out;
    for(i = 0; i < total; i++)
    {
        in.getdata(a[i]);
        Student::func();
    }

    for(i = 0; i < total; i++)
    {
        out.show(a[i]);
    }

    Student b = a[0];
    out.show(b);

    delete [] a;
    return 0;
}
