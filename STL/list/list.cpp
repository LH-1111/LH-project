#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void printlist(const list<int> &l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
        /* code */
    }
    cout << endl;
}
int main()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    l.push_back(8);
    l.push_back(9);

    if (!l.empty())
    {
        cout << "list 不为空" << endl;
        cout << "list size:" << l.size() << endl;
        l.resize(20);
    }
    printlist(l);
}