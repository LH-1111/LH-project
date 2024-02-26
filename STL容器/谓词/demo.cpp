#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class One
{
public:
    bool operator()(int val)
    {
        return val == 1;
    }
};
class Two
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
void testone()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it = find_if(v.begin(), v.end(), One());
    if (it == v.end())
    {
        cout << "没找到!" << endl;
    }
    else
    {
        cout << "找到:" << *it << endl;
    }
}
void testtwo()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    sort(v.begin(), v.end(), Two());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
}
int main()
{
    testtwo();
    return 0;
}