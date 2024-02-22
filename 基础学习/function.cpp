#include <iostream>
#include <string>
using namespace std;
int addnum(int a, int b = 2, int c = 2);
void fun(int & a);
void fun(const int & a);

int main()
{
    const int a = 10 ;
    fun(a);
}
int addnum(int a, int b, int c)
{
    return a + b + c;
}

void fun(int & a)
{
    cout << "fun1" << a << endl;
}

void fun(const int & a)
{
    cout << "fun2" << a << endl;
}
