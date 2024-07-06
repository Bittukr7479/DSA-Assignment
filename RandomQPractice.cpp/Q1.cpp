#include <iostream>
#include <stdio.h>
using namespace std;
class Complex
{
private:
    int a, b;

public:
    void setData(int x, int y)
    {
        a = x;
        b = y;
    }
    void showData()
    {
        cout << "\na= " << a << "b= " << b;
    }
    friend ostream &operator<<(ostream &, Complex);
    friend istream &operator>>(istream &, Complex &);
};
ostream &operator<<(ostream &dout, Complex c)
{
    dout << "\na = " << c.a << "\nb= " << c.b;
    return (dout);
}
istream &operator>>(istream &din, Complex &c)
{
    din >> c.a >>c.b;
    return (din);
}

int main()
{
    Complex c1;
    cout << "Enter a complex number: ";
    cin >> c1;
    cout << "You entered: ";
    cout << c1 ;
}