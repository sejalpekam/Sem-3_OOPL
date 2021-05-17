#include <QCoreApplication>
#include <iostream>
using namespace std;

class Complex{
private:
    float real, imag;
public:
    Complex(){
        real = 0;
        imag = 0;
    }
    Complex(float a, float b){
        real = a;
        imag = b;
    }
    Complex operator +(Complex const &c){
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
    Complex operator -(Complex const &c){
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }
    Complex operator *(Complex const &c){
        Complex temp;
        temp.real = real*c.real - imag*c.imag;
        temp.imag = real*c.imag + imag*c.real;
        return temp;
    }
    friend ostream &operator<<(ostream &o, Complex &c){
        if (c.imag<0){
            o<<c.real<<c.imag<<"i"<<endl;
        }
        else{
            o<<c.real<<"+"<<c.imag<<"i"<<endl;
        }
        return o;
    }
    friend istream &operator>>(istream &i, Complex &c){
        cout<<"Enter value of real part: ";
        i>>c.real;
        cout<<"Enter value of imaginary part: ";
        i>>c.imag;
        return i;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int operation;
    bool cont = true;
    Complex x,y,add,subtract,multiply;

        cout<<"Enter value of x"<<endl;
        cin>>x;
        cout<<x;
        cout<<"Enter value of y"<<endl;
        cin>>y;
        cout<<y;
    while(cont){
        cout<<"Enter choice of operation: \n1.Addition \n2.Subtraction \n3.Multiplication \n4.Exit"<<endl;
        cin>>operation;
        switch (operation){
        case 1:
            add = x + y ;
            cout<<add;
            break;
        case 2:
            subtract = x - y;
            cout<<subtract;
            break;
        case 3:
            multiply = x*y;
            cout<<multiply;
            break;
        case 4:
            cont = false;
            break;

        }
    }

    return a.exec();
}
