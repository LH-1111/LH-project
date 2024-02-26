#include <iostream>
#include <map>
using namespace std;

void printmap(const map<int, int> &m)
{

    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}
void test()
{
    // 创建map容器
    map<int, int> m;
    m.insert(make_pair(0, 1));
    m.insert(make_pair(1, 1));
    m.insert(make_pair(2, 1));
    m.insert(make_pair(3, 1));
    printmap(m);
}

void testSize()
{
    // 创建map容器
    map<int, int> m;
    m.insert(make_pair(0, 1));
    m.insert(make_pair(1, 1));
    m.insert(make_pair(2, 1));
    m.insert(make_pair(3, 1));
    printmap(m);
    m.clear();
    if (!m.empty())
    {
        cout << "map isn't null:" << m.size() << endl;
    }
    else
    {
        cout << "map is null:" << m.size() << endl;
    }
}

void testdele()
{
    // 创建map容器
    map<int, int> m;
    m.insert(make_pair(0, 1));
    m.insert(make_pair(1, 1));
    m.insert(make_pair(2, 1));
    m.insert(make_pair(3, 1));

    m.erase(1);
    m.erase(m.begin());
    printmap(m);
}

void testfind()
{
    // 创建map容器
    map<int, int> m;
    m.insert(make_pair(0, 1));
    m.insert(make_pair(1, 1));
    m.insert(make_pair(2, 1));
    m.insert(make_pair(3, 1));
    map<int, int>::iterator it = m.find(0);
    if(it != m.end()){
        int num = m.count(0);
        cout << (*it).first << " " << it->second << endl;
        cout << "num : " << " " << it->second << endl;
    }else{
        cout << "not find" << endl;
    }
}
int main()
{
    testfind();
}