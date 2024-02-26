#include <iostream>
#include <string>
using namespace std;

class MyAdd
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

class Myprint
{
public:
    Myprint()
    {
        this ->count = 0;
    }
    void operator()(string a)
    {
        cout << a << endl;
        count++;
    }

    int count;
};

int main()
{
    MyAdd add;
    cout << add(1, 2) << endl;
    Myprint myprint;
    myprint("hello world!");
    myprint("hello world!");
    myprint("hello world!");
    cout << myprint.count << endl;
}