
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*位置调整，间隔一个*/
void test1()
{
    int a[10] = {1, 0, 1, 0, 0, 0, 1, 0, 0, 1};
    vector<int> v;
    int count = 0;
    for (int i = 0; i < (sizeof(a) / sizeof(int)); i++)
    {
        v.push_back(a[i]);
    }

    for (int i = 0; i < v.size() - 2; i++)
    {
        if ((v[i] == 0) && (v[i + 2] == 0) && (v[i + 1] == 0))
            count++;
    }

    cout << "count:" << count << endl;
}

/*子串问题*/
void test2()
{
    vector<int> baselist;
    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            baselist.push_back(j);
        }
    }
    vector<int> sonlist;
    for (int j = 0; j < 10; j++)
    {
        sonlist.push_back(j);
    }
    for (int i = 0; i < baselist.size() - sonlist.size(); i++){
        for(int j = 0 ; j< sonlist.size();j++){
            if(sonlist[j] == baselist[i]){
                count++;
                i = i+sonlist.size()-1;
            }
        }
    }
    cout<<"count: "<<count<<endl;
}



int main()
{
    test2();
}