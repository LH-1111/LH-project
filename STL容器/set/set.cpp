#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
class Person;
class mycompare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};



class Person
{
public:
    string m_name;
    int m_age;
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
};

class compareClass
{
public:
    bool operator()(const Person &a,const Person &b)
    {
        return a.m_age > b.m_age;
    }
};

void printSet(const set<int> &s)
{
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
// set 插入
void test()
{
    set<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    s1.insert(6);
    s1.insert(0);
    printSet(s1);
}

void test2()
{
    set<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    s1.insert(6);
    s1.insert(0);
    // s1.clear();
    if (s1.empty())
    {
        cout << "set is null" << endl;
    }
    else
    {
        cout << "set isn't null  size:" << s1.size() << endl;
    }

    set<int> s2(s1);
    printSet(s2);
    s2.insert(10);
    s2.swap(s1);
    printSet(s2);
    printSet(s1);
}

void findandcount()
{
    set<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    s1.insert(6);
    s1.insert(0);
    set<int>::iterator it = s1.find(0);
    if (it != s1.end())
    {
        cout << "finded " << *it << endl;
        int count = s1.count(0);
        cout << "count： " << count << endl;
    }
    else
    {
        cout << "don't finded " << *it << endl;
    }
}

void setdiff()
{
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    if (ret.second)
    {
        cout << "insert succeeful " << *ret.first << endl;
    }
    ret = s.insert(10);
    if (ret.second)
    {
        cout << "insert succeeful" << endl;
    }
    else
    {
        cout << "insert fail" << endl;
    }
}

void testpair()
{
    pair<string, int> p(string("aaa"), 10);
    cout << "name: " << p.first << " age :" << p.second << endl;
    pair<string, int> p2 = make_pair("bbbb", 11);
    cout << "name: " << p2.first << " age :" << p2.second << endl;
}

void testsort()
{
    set<int, mycompare> s;
    s.insert(1);
    s.insert(12);
    s.insert(9);
    s.insert(52);
    for (set<int, mycompare>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

void testsort2()
{
    set<Person,compareClass> persons;
    Person p1("aaa", 1);
    Person p2("bbb", 2);
    Person p3("ccc", 3);
    persons.insert(p1);
    persons.insert(p2);
    persons.insert(p3);
    for (set<Person,compareClass>::iterator it = persons.begin(); it != persons.end(); it++)
    {
        cout << "name:" << (it->m_name) << " age :   " << (it->m_age)<<endl;
    }
    cout << endl;
}

int main()

{
    testsort2();
}