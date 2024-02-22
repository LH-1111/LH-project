#include <iostream>
#include <string>
using namespace std;

void showValue(const int &val);

int main()
{
    int a = 10;
    int &ref = a;
    int *const p = &a;
    cout << ref << endl;
    cout << *p << endl;

    *p = 20;
    cout << ref << endl;
    cout << *p << endl;

    ref = 30;
    cout << ref << endl;
    cout << *p << endl;
    showValue(a);
    cout << ref << endl;
    cout << *p << endl;
}

void showValue(const int &val)
{
    cout <<"showValue:"<< val << endl;
}