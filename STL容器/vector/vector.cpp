#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int> v2(v.begin(), v.end());
    printVector(v2);

    vector<int> v3(10, 10);
    printVector(v3);

    vector<int> v4(v3);
    printVector(v4);
}

void testSize()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    cout << v.size() << endl;
    cout << v.empty() << endl;
    cout << v.capacity() << endl;
    v.resize(15);
    printVector(v);
    v.resize(5);
    printVector(v);
}
// * `push_back(ele);`                                         //尾部插入元素ele
// * `pop_back();`                                                //删除最后一个元素
// * `insert(const_iterator pos, ele);`        //迭代器指向位置pos插入元素ele
// * `insert(const_iterator pos, int count,ele);`//迭代器指向位置pos插入count个元素ele
// * `erase(const_iterator pos);`                     //删除迭代器指向的元素
// * `erase(const_iterator start, const_iterator end);`//删除迭代器从start到end之间的元素
// * `clear();`                                                        //删除容器中所有元素
void insertOrdele()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // v.pop_back();

    v.insert(v.begin(), 10);
    v.erase(v.begin());
    v.clear();
    printVector(v);
}

void reserve()
{
    vector<int> v;
    int *p = nullptr;
    int count = 0;
    v.reserve(1000000);
    for (int i = 0; i < 1000000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            count++;
            cout << "end: " << v.back()<< endl;
        }
    }
    cout << "end22: " << v.back()<< endl;
    cout << "count: " << count << endl;
}
int main()
{
    reserve();
    return 0;
}